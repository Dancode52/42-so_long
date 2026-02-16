/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_validity_checks_utils_1.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:51:18 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 16:02:51 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t	map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	check_top_bottom_walls(char **map, t_map_errors *error)
{
	size_t	row;
	size_t	column;
	size_t	rowmax;

	if (error->dimension_error)
		return ;
	row = 0;
	column = 0;
	rowmax = map_height(map);
	while (map[row][column])
	{
		if (map[row][column] != '1' || map[rowmax - 1][column] != '1')
		{
			error->topbot_error = 1;
			return ;
		}
		column++;
	}
}

void	check_left_right_walls(char **map, t_map_errors *error)
{
	size_t	row;
	size_t	len;

	if (error->dimension_error)
		return ;
	row = 0;
	len = ft_strlen(map[row]);
	while (map[row])
	{
		if (map[row][0] != '1' || map[row][len - 1] != '1')
		{
			error->leftright_error = 1;
			return ;
		}
		row++;
	}
}



