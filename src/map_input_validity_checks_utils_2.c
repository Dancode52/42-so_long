/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_validity_checks_utils_2.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:45:10 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 19:19:41 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void check_valid_char(char map_tile, t_map_errors *error)
{
	char	*valid_chars;

	valid_chars = "01CEP";
	if (!ft_strchr(valid_chars, map_tile))
		error->char_error = 1;
}

void count_player(t_map_count *map_info, char map_tile)
{
	if (map_tile == 'P')
		map_info->player_count++;
	// if (p_count != 1)
	// {
	// 	free_memory(map);
	// 	write(2, "Error\n", 6);
	// 	write(2, "Map must have only one player spawn\n", 36);
	// 	exit(EXIT_FAILURE);
	// }
}

void	count_exit(t_map_count *map_info, char map_tile)
{
	if (map_tile == 'E')
		map_info->exit_count++;
	// if (e_count != 1)
	// {
	// 	free_memory(map);
	// 	write(2, "Error\n", 6);
	// 	write(2, "Map must have only one player spawn\n", 36);
	// 	exit(EXIT_FAILURE);
	// }
}

void	count_collectible(t_map_count *map_info, char map_tile)
{
	if (map_tile == 'C')
		map_info->collect_count++;
	// if (c_count < 1)
	// {
	// 	free_memory(map);
	// 	write(2, "Error\n", 6);
	// 	write(2, "Map must have only one player spawn\n", 36);
	// 	exit(EXIT_FAILURE);
	// }
}

void	validate_count(t_map_count *map_info, t_map_errors *error)
{
	if (map_info->player_count != 1)
		error->player_error = 1;
	if (map_info->exit_count != 1)
		error->exit_error = 1;
	if (map_info->collect_count < 1)
		error->collecible_error = 1;
}

