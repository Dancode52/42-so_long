/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_inpuct_checks_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:51:18 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/14 17:26:19 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

size_t	map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	check_top_bottom_walls(char **map)
{
	size_t	row;
	size_t	column;
	size_t	rowmax;

	row = 0;
	column = 0;
	rowmax = map_height;
	while (map[row][column])
	{
		if (map[row][column] != '1' || map[rowmax - 1][column] != '1')
		{
			free_memory(map);
			write(2, "Error\n", 6);
			write(2, "Top or bottom wall is invalid.", 30);
			write(2, " Walls must only contain '1's\n", 30);
			exit(EXIT_FAILURE);
		}
		column++;
	}
}

void	check_left_right_walls(char **map)
{
	size_t	row;
	size_t	column;
	size_t	len;

	row = 0;
	len = ft_strlen(map[row]);
	while (map[row])
	{
		if (map[row][0] != '1' || map[row][len - 1] != '1')
		{
			free_memory(map);
			write(2, "Error\n", 6);
			write(2, "Left or right wall is invalid.", 30);
			write(2, " Walls must only contain '1's\n", 30);
			exit(EXIT_FAILURE);
		}
	}
}
