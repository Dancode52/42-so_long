/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_validity_checks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:30:29 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 15:48:02 by dlanehar         ###   ########.fr       */
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

// void	empty_line_check(char **map, t_map_errors *error)
// {
// 	size_t	row;
// 	size_t	column;

// 	row = 0;
// 	while (map[row])
// }

void dimension_check(char **map, t_map_errors *error)
{
	size_t	row;
	size_t	len_to_match;
	size_t	len;

	row = 0;
	len_to_match = 0;
	while (map[row])
	{
		len = ft_strlen(map[row]);
		if (!len_to_match)
			len_to_match = len;
		if (len_to_match != len)
			{
				error->dimension_error = 1;
				// free_memory(map);
				// write(2, "Error\n", 6);
				// write(2, "Inconsistent map line length\n", 20);
				// exit(EXIT_FAILURE);
			}
		row++;
	}
}

void wall_check(char **map, t_map_errors *error)
{
	check_top_bottom_walls(map, error);
	check_left_right_walls(map, error);
}

void	parameter_check(char **map, t_map_count *count, t_map_errors *error)
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
			count_player(count, map[row][column]);
			count_exit(count, map[row][column]);
			count_collectible(count, map[row][column]);
			column++;
		}
		row++;
	}
	validate_count(count, error);
}
