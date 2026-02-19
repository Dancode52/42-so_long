/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:15:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/19 14:51:54 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void store_player(t_map_count *map_info, size_t row, size_t column)
{
	map_info->player_pos[0] = row;
	map_info->player_pos[1] = column;
}

void store_exit(t_map_count *map_info, size_t row, size_t column)
{
	map_info->exit_pos[0] = row;
	map_info->exit_pos[1] = column;
}

void store_collect(t_map_count *m_info, size_t row, size_t col, char **map)
{
	static size_t count = 0;
	size_t fail;

	fail = 0;
	if (count < m_info->collect_count)
	{
		m_info->collect_pos[count] = ft_calloc(2, sizeof(size_t));
		if (!m_info->collect_pos[count])
		{
			free_memory(map);
			while (fail < row)
			{
				free(m_info->collect_pos[fail]);
				fail++;
			}
			free(m_info->collect_pos);
			ft_putstr_fd("Error\nMalloc failure\n", 2);
			exit(EXIT_FAILURE);
		}
		m_info->collect_pos[count][0] = row;
		m_info->collect_pos[count][1] = col;
	}
	count ++;
}

void	store_info(char **map, t_map_count *m_info)
{
	size_t	row;
	size_t	column;

	row = 0;
	m_info->collect_pos = ft_calloc(m_info->collect_count, sizeof(size_t *));
	if (!m_info->collect_pos)
	{
		free_memory(map);
		ft_putstr_fd("Error\nMalloc failure\n", 2);
		exit(EXIT_FAILURE);
	}
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'P')
				store_player(m_info, row, column);
			if (map[row][column] == 'E')
				store_exit(m_info, row, column);
			if (map[row][column] == 'C')
				store_collect(m_info, row, column, map);
			column++;
		}
		row++;
	}
}




void input_validity(char **map, t_map_count *map_info, t_map_errors *error)
{
	//empty_line_check(map, error);
	ft_printf("Checking dimensions\n");
	dimension_check(map, map_info, error);
	ft_printf("Checking walls\n");
	wall_check(map, map_info, error);
	ft_printf("Checking map chars\n");
	parameter_check(map, map_info, error);
}

void validity_check(char **map, t_map_count *map_info)
{
	//t_map_count count;
	t_map_errors error;

	ft_bzero(map_info, sizeof(t_map_count));
	ft_bzero(&error, sizeof(t_map_errors));
//---- check the validity of the input map
	input_validity(map, map_info, &error);
	ft_printf("Checks complete!\n");
//---- check if map is playable
	ft_printf("Storing info\n");
	store_info(map, map_info);
	if (!error.is_error)
		flood_fill(map, map_info, &error);
	error_check(map, &error, map_info);
}
