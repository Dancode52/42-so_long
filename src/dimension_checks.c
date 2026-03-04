/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 08:59:52 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/04 11:57:24 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_width(char **map, t_map_count *map_info, t_map_errors *error)
{
	size_t	i;

	i = 0;
	while (i < map_info->map_height)
	{
		if (map_info->map_width != ft_strlen(map[i]))
		{
			error->rectangle_error = 1;
			error->dimension_error = 1;
			break ;
		}
		i++;
	}
	if (map_info->map_width < 3 || map_info->map_height < 3)
	{
		if (map_info->map_width < 3)
			error->width_error = 1;
		if (map_info->map_height < 3)
			error->height_error = 1;
	}
	return ;
}

void	three_by_three(t_map_count *map_info, t_map_errors *error)
{
	if (map_info->map_width == 3 && map_info->map_height == 3)
		error->three_by_three = 1;
}
