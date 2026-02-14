/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_input_checks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:30:29 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/14 18:00:43 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>


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

static void	free_memory(char **badmem)
{
	int	i;

	i = 0;
	while (badmem[i])
	{
		free(badmem[i]);
		i++;
	}
	free(badmem);
	return ;
}

void valid_char_check(char **map)
{
	size_t	row;
	size_t	column;
	char	*valid_chars;

	valid_chars = "01CEP";
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (!ft_strchr(valid_chars, map[row][column]))
				{
					free_memory(map);
					write(1, "this ain't it chief\n", 20);
					exit(EXIT_FAILURE);
				}
			column++;
		}
		row++;
	}
}

void dimension_check(char **map)
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
				free_memory(map);
				write(2, "Error\n", 6);
				write(2, "Inconsistent map line length\n", 20);
				exit(EXIT_FAILURE);
			}
		row++;
	}
}

void border_control(char **map)
{
	check_top_bottom_walls(map);
	check_left_right_walls(map);
}

void player_check(char **map)
{
	size_t	p_count;
	size_t	row;
	size_t	column;

	p_count = 0;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'P')
				p_count++;
			column++;
		}
		row++;
	}
	if (p_count != 1)
	{
		free_memory(map);
		write(2, "Error\n", 6);
		write(2, "Map must have only one player spawn\n", 36);
		exit(EXIT_FAILURE);
	}
}

void	collectible_check(char **map)
{
	size_t	collect_count;
	size_t	row;
	size_t	column;

	collect_count = 0;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'C')
				collect_count++;
			column++;
		}
		row++;
	}
	if (collect_count < 1)
	{
		free_memory(map);
		write(2, "Error\n", 6);
		write(2, "Map must have more than one collectible\n", 40);
		exit(EXIT_FAILURE);
	}
}

void	check_exit(char **map)
{
	size_t	exit_count;
	size_t	row;
	size_t	column;

	exit_count = 0;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'C')
				exit_count++;
			column++;
		}
		row++;
	}
	if (exit_count != 1)
	{
		free_memory(map);
		write(2, "Error\n", 6);
		write(2, "Map must have an exit\n", 23);
		exit(EXIT_FAILURE);
	}
}
