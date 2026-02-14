/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:57:22 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/14 13:17:56 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	int	i;
	char	**map;

	if (argc != 2)
		error_function(-2);
	map = map_maker(argv[1]);
	if (!map)
		return (0);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	printf("It worked! i = %d. GG!\n", i);
	free_memory(map);
}
