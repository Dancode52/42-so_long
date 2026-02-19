/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:15:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 10:24:21 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void input_validity(char **map, t_map_count *map_info, t_map_errors *error)
{
	//empty_line_check(map, error);
	ft_printf("Checking dimensions\n");
	dimension_check(map, map_info, error);
	ft_printf("Checking walls\n");
	wall_check(map, map_info, error);
	ft_printf("Checking map chars\n");
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
	ft_printf("Checks complete!\n");
//---- check if map is playable
	//flood_fill_part(map);
	error_check(map, &error);
}
