/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:34:51 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:29:45 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_memory(char **memory)
{
	int	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	return ;
}

void	malloc_fail(char **map)
{
	free_memory(map);
	ft_putstr_fd("Error\nMalloc failure\n", 2);
	exit(EXIT_FAILURE);
}

void	printmap(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}
