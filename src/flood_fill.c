/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:45:00 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/19 16:12:00 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	go_right_till_wall(char **map, size_t row, size_t column)
{
	while (map[row][column] != '1')
	{
		map[row][column] = 'X';
		column++;
	}
	return (1);
}

int	go_left_till_wall(char **map, size_t row, size_t column)
{
	while (map[row][column] != '1')
	{
		map[row][column] = 'X';
		column--;
	}
	return (1);
}

int	go_up_till_wall(char **map, size_t row, size_t column)
{
	while (map[row][column] != '1')
	{
		map[row][column] = 'X';
		row++;
	}
	return (1);
}

int go_down_till_wall(char **map, size_t row, size_t column)
{
	while (map[row][column] != '1')
	{
		map[row][column] = 'X';
		row--;
	}
	return (1);
}


void	set_start_point(size_t *row, size_t *column, t_map_count *map_info)
{
	*row = map_info->player_pos[0];
	*column = map_info->player_pos[1];
}

void	flood_fill(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	row;
	size_t	column;
	char	**tmp;

	tmp = map;
	(void)error;
	//set the point from which we will start the fill
	set_start_point(&row, &column, map_info);
	//have a function that sets the use looking for adjacent squares
		//continue in a direcion until a wall is hit
		//first test is with going right
	go_right_till_wall(tmp, row, column);
	printmap(tmp);
	go_left_till_wall(tmp, row, column);
	printmap(tmp);
	go_up_till_wall(tmp, row, column);
	printmap(tmp);
	go_down_till_wall(tmp, row, column);
	printmap(tmp);
	//these work? now make it so they are called in the corresponding conditions
	//call down if top/right are walls, and if left is painted etc
}
