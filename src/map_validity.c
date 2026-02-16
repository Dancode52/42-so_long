/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:15:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 19:19:39 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_check(char **map, t_map_errors *error)
{
	if (error->is_error)
	{
		ft_putstr_fd("Error\n", 2);
		if (error->dimension_error)
			ft_putstr_fd("Inconsistent map line length\n", 2);
		if (error->topbot_error)
			ft_putstr_fd("1 missing in top or bottom wall.\n", 2);
		if (error->leftright_error)
			ft_putstr_fd("1 missing in left or right wall.\n", 2);
		if (error->player_error)
			ft_putstr_fd("Map must only have one player\n", 2);
		if (error->exit_error)
			ft_putstr_fd("Map must only have one exit", 2);
		if (error->collecible_error)
			ft_putstr_fd("Map must have more than one colletible", 2);
		if (error->char_error)
			ft_putstr_fd("Invalid map chars. Valid chars are 01CEP", 2);
		if (error->fill_error)
			ft_putstr_fd("Map is not playable. Player must be able to reach all collectibles and the exit.", 2);
		if (error->emptyline)
			write(2, "empty line\n", 11);
		free_memory(map);
		exit(EXIT_FAILURE);
	}
}

void input_validity(char **map, t_map_count *map_info, t_map_errors *error)
{
	//empty_line_check(map, error);
	dimension_check(map, map_info, error);
	wall_check(map, map_info, error);
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
//---- check if map is playable
	//flood_fill_part(map);
	error_check(map, &error);
}
