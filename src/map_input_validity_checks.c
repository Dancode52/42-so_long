/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_validity_checks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:30:29 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:39:04 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// //---- check that there are only valid chars in the map strings
// 	valid_char_check(map);
// //---- check the dimensions of the map. must be rectangular.
// 	dimension_check(map);
// //---- check the border of the map. it must be surrounded by walls of 1s
// 	border_control(map);
// //--- check there's only 1 player
// 	player_check(map);
// //-- check there's only one exit
// 	wheres_the_exit(map);

void	dimension_check(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	i;

	i = 0;
	map_info->map_width = ft_strlen(map[i]);
	map_info->map_height = map_height(map);
	while (i < map_info->map_height)
	{
		if (map_info->map_width != ft_strlen(map[i]))
			error->dimension_error = 1;
		i++;
	}
	if (map_info->map_width < 3 || map_info->map_height < 3)
	{
		if (map_info->map_width < 3)
			error->width_error = 1;
		if (map_info->map_height < 3)
			error->height_error = 1;
	}
	if (map_info->map_width == 3 && map_info->map_height == 3)
		error->three_by_three = 1;
	if (error->dimension_error || error->width_error
		|| error->height_error || error->three_by_three)
		error->is_error = 1;
}

void	wall_check(char **map, t_map_count *map_info, t_map_errors *error)
{
	check_top_bot(map, map_info, error);
	check_left_rht(map, map_info, error);
}

void	parameter_check(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t		row;
	size_t		column;

	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			check_valid_char(map[row][column], error);
			count_player(map_info, map[row][column]);
			count_exit(map_info, map[row][column]);
			count_collectible(map_info, map[row][column]);
			column++;
		}
		row++;
	}
	validate_count(map_info, error);
}
