/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/24 13:16:34 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_map_count	map_info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease provide a map.\n", 2);
		return (0);
	}
	map = map_maker(argv[1], &map_info);
	ft_printf("hello");
	int i = gameshit(map, map_info);
	ft_printf("%i\n", i);
	if (!map)
		return (0);
	free_memory(map);
	free_map_info(&map_info);
}
