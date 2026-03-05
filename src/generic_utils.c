/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:34:51 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/05 13:28:50 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_memory(char **memory)
{
	int	i;

	i = 0;
	if (!memory)
		return ;
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

mlx_image	load_image(t_game_state *game, char *str)
{
	mlx_image	img;

	img = mlx_new_image_from_file(game->mlx, str, &game->img_w, &game->img_h);
	if (!img)
	{
		ft_printf("Error\nTexture loading failed\n");
		free_memory(game->map);
		free_map_info(&game->map_info);
		destroy_on_error(game);
		exit(EXIT_FAILURE);
	}
	return (img);
}

mlx_window	load_window(t_game_state *game)
{
	mlx_window	win;

	win = mlx_new_window(game->mlx, &game->win_info);
	if (!win)
	{
		free_memory(game->map);
		free_map_info(&game->map_info);
		ft_printf("Error\nWindow loading failed\n");
		mlx_destroy_context(game->mlx);
		exit(EXIT_FAILURE);
	}
	return (win);
}
