/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 11:23:24 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	size_t	i;
	char	**map;
	t_map_count map_info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease provide a map.\n", 2);
		return (0);
	}
	map = map_maker(argv[1], &map_info);
	if (!map)
		return (0);
	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
	i = 0;
	while (i < map_info.collect_count)
	{
		printf("collect pos 1: %zu\ncollect pos 2: %zu\n", map_info.collect_pos[i][0], map_info.collect_pos[i][1]);
		i++;
	}
	ft_printf("It worked! i = %zu. GG!\n", i);
	free_memory(map);
	i = 0;
	while (i < map_info.collect_count)
		free(map_info.collect_pos[i++]);
	free(map_info.collect_pos);
}

void	printmap(char **map)
{
	size_t i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}
