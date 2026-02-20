/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:52:33 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:45:05 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_maker(char *map_path, t_map_count *map_info)
{
	char	**map;

	map = map_loading(map_path);
	if (!map)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		exit(EXIT_FAILURE);
	}
	validity_check(map, map_info);
	return (map);
}
