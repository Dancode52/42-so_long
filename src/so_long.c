/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/16 19:19:40 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	int	i;
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
	ft_printf("It worked! i = %d. GG!\n", i);
	free_memory(map);
}
