/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:52:33 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/14 18:02:08 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

void	error_function(int error);

void	error_function(int error)
{
	if (error == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Malloc error\n", 13);
		exit(EXIT_FAILURE);
	}
	if (error == -2)
	{
		write(2, "Error\n", 6);
		write(2, "Invalid number of args or no .ber file.\n", 40);
		write(2, "Valid input is './so_long path/to/map.ber'.\n", 44);
		exit(EXIT_FAILURE);
	}
	if (error == -3)
	{
		write(2, "Error\n", 6);
		write(2, "Map invalid. A line of the given map is too long.\n", 54);
		write(2, "Make sure all lines are of equal length \n", 41);
		exit(EXIT_FAILURE);
	}
}

char **map_maker(char *map_path)
{
	char **map;
//---- load the map
	map = map_loading(map_path);
//---- check if map is valid
	validity_check(map);
	return (map);
}
