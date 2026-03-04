/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:58:57 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/04 13:42:13 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	get_enemy_spawn(t_game_state *game)
{
	size_t	rand_x;
	size_t	rand_y;

	rand_x = 0;
	rand_y = 0;
	srand(time(NULL));
	while (game->map[rand_y][rand_x] != '0')
	{
		rand_y = rand() % game->map_info.map_height;
		rand_x = rand() % game->map_info.map_width;
	}
	game->v_chic.spawn_x = rand_x;
	game->v_chic.spawn_y = rand_y;
}

void	draw_enemy(t_game_state *game)
{
	size_t		row;
	size_t		column;
	mlx_image	sprite;

	sprite = game->v_chic.v_down;
	row = game->v_chic.spawn_y;
	column = game->v_chic.spawn_x;
	// if (game->player_dir == P_RIGHT)
	// 	sprite = game->img_p_right;
	// if (game->player_dir == P_LEFT)
	// 	sprite = game->img_p_left;
	// if (game->player_dir == P_UP)
	// 	sprite = game->img_p_up;
	// if (game->player_dir == P_DOWN)
	// 	sprite = game->img_p_down;
	mlx_put_transformed_image_to_window(game->mlx, game->win, sprite,
		column * game->tile_size_px, row * game->tile_size_px - 32, 4, 4, 0);
}
