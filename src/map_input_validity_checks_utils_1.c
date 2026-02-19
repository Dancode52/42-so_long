/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_validity_checks_utils_1.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:51:18 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 15:35:36 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

void	empty_line_check(char *res)
{
	size_t	i;
	size_t	newline_count;

	i = 0;
	newline_count = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			newline_count++;
		else
			newline_count = 0;
		if (newline_count > 1)
			{
				free(res);
				ft_putstr_fd("Error\nEmpty line in map file\n", 2);
				exit(EXIT_FAILURE);
			}
		i++;
	}
}

size_t	map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	check_top_bottom_walls(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	row;
	size_t	column;
	size_t	rowmax;

	if (error->dimension_error)
		return ;
	row = 0;
	column = 0;
	rowmax = map_info->map_height;
	if (rowmax < 1)
		return ;
	while (map[row][column])
	{
		if (map[row][column] != '1' || map[rowmax - 1][column] != '1')
		{
			error->is_error = 1;
			error->topbot_error = 1;
			return ;
		}
		column++;
	}
}

void	check_left_right_walls(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	row;
	size_t	len;

	(void)map_info;
	// if (error->dimension_error)
	// 	return ;
	row = 0;
	while (map[row])
	{
		len = ft_strlen(map[row]);
		printf("len = %zu\n", len);
		if (len == 0)
		{
			error->is_error = 1;
			error->emptyline = 1;
			return ;
		}
		if (map[row][0] != '1' || map[row][len - 1] != '1')
		{
			error->is_error = 1;
			error->leftright_error = 1;
			return ;
		}
		row++;
	}
	printmap(map);
}



