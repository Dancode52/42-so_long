/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:36:21 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 11:31:35 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map_info(t_map_count *map_info)
{
	size_t	i;

	i = 0;
	while (i < map_info->collect_count)
	{
		free(map_info->collect_pos[i]);
		i++;
	}
	free(map_info->collect_pos);
}

void	error_check(char **map, t_map_errors *error, t_map_count *map_info)
{
	(void)map_info;
	if (error->is_error)
	{
		ft_putstr_fd("Error\n", 2);
		if (error->dimension_error || error->topbot_error
			|| error->leftright_error)
			dimension_error(error);
		if (error->player_error)
			ft_putstr_fd("Map must contain exactly one player spawn\n", 2);
		if (error->exit_error)
			ft_putstr_fd("Map must contain exactly one exit\n", 2);
		if (error->collecible_error)
			ft_putstr_fd("Map must contain at least one collectible\n", 2);
		if (error->char_error)
			ft_putstr_fd("Map must only be made of the following: 01CEP\n", 2);
		if (error->fill_error)
			ft_putstr_fd("Player cannot reach collectibles or exit.\n", 2);
		if (error->emptyline)
			ft_putstr_fd("Empty line present in map\n", 2);
		free_map_info(map_info);
		free_memory(map);
		exit(EXIT_FAILURE);
	}
}

void	dimension_error(t_map_errors *error)
{
	if (error->dimension_error)
		ft_putstr_fd("Map must be a rectangle\n", 2);
	if (error->height_error)
		ft_putstr_fd("Map must be at least 3 tall\n", 2);
	if (error->width_error)
		ft_putstr_fd("Map must be at least 3 wide\n", 2);
	if (error->three_by_three)
		ft_putstr_fd("Map cannot be 3 by 3\n", 2);
	if (error->topbot_error)
		ft_putstr_fd("Map is missing walls in top or bottom row.\n", 2);
	if (error->leftright_error)
		ft_putstr_fd("Map is missing walls in left or right column.\n", 2);
}
