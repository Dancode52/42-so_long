/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:15:05 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:28:09 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	input_validity(char **map, t_map_count *map_info, t_map_errors *error)
{
	dimension_check(map, map_info, error);
	wall_check(map, map_info, error);
	parameter_check(map, map_info, error);
}

void	validity_check(char **map, t_map_count *map_info)
{
	t_map_errors	error;

	ft_bzero(map_info, sizeof(t_map_count));
	ft_bzero(&error, sizeof(t_map_errors));
	input_validity(map, map_info, &error);
	store_info(map, map_info);
	if (!error.is_error)
		flood_fill(map, map_info, &error);
	error_check(map, &error, map_info);
}
