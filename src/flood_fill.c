/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:45:00 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:35:33 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_copy(char **map, t_map_count *map_info)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = malloc((map_info->map_height + 1) * sizeof(char *));
	if (!copy)
	{
		free_memory(map);
		free_map_info(map_info);
		exit(EXIT_FAILURE);
	}
	while (i < map_info->map_height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_memory(map);
			free_map_info(map_info);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	set_start_point(size_t *row, size_t *column, t_map_count *map_info)
{
	*row = map_info->player_pos[0];
	*column = map_info->player_pos[1];
}

void	is_map_playable(char **copy, t_map_errors *error)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'P' || copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				error->is_error = 1;
				error->fill_error = 1;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	flood_fill(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	row;
	size_t	column;
	char	**copy;

	(void)error;
	copy = map_copy(map, map_info);
	set_start_point(&row, &column, map_info);
	get_filling(copy, row, column, map_info);
	is_map_playable(copy, error);
	free_memory(copy);
}

void	get_filling(char **map, size_t row, size_t col, t_map_count *map_info)
{
	if ((map[row][col] == 'X' ) || (map[row][col] == '1'))
		return ;
	if (map[row][col] == '0' || map[row][col] == 'C'
		|| map[row][col] == 'E' || map[row][col] == 'P')
		map[row][col] = 'X';
	get_filling(map, row - 1, col, map_info);
	get_filling(map, row + 1, col, map_info);
	get_filling(map, row, col - 1, map_info);
	get_filling(map, row, col + 1, map_info);
	return ;
}
