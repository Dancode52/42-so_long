/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:52:33 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 15:22:06 by dlanehar         ###   ########.fr       */
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
		m_info->collect_pos[count] = ft_calloc(2, sizeof(int));
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

void	store_info(char **map, t_map_count *map_info)
{
	size_t	row;
	size_t	column;

	row = 0;
	map_info->collect_pos = ft_calloc(map_info->collect_count, sizeof(size_t *));
	if (!map_info->collect_pos)
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
				store_player(map_info, row, column);
			if (map[row][column] == 'E')
				store_exit(map_info, row, column);
			if (map[row][column] == 'C')
				store_collect(map_info, row, column, map);
			column++;
		}
		row++;
	}
}

char **map_maker(char *map_path, t_map_count *map_info)
{
	char **map;

//---- load the map
	ft_printf("Map loading...\n");
	map = map_loading(map_path);
	ft_printf("Map loaded!\n");
	printmap(map);
//---- check if map is valid
	if (!map)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		exit(EXIT_FAILURE);
	}
	validity_check(map, map_info);
	ft_printf("Storing info\n");
	store_info(map, map_info);
	return (map);
}
