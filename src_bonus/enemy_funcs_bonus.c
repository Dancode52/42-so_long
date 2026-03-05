/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:58:57 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/05 15:20:05 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include <stdio.h>

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
	if (game->v_chic.vc_dir == P_RIGHT)
		sprite = game->v_chic.v_right;
	if (game->v_chic.vc_dir == P_LEFT)
		sprite = game->v_chic.v_left;
	if (game->v_chic.vc_dir == P_UP)
		sprite = game->v_chic.v_up;
	if (game->v_chic.vc_dir == P_DOWN)
		sprite = game->v_chic.v_down;
	mlx_put_transformed_image_to_window(game->mlx, game->win, sprite,
		column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void	do_move(t_game_state *game, int dir)
{
	int i;
	int tryagain = 0;
	t_move	*moves;

	(void)dir;
	moves = init_moves();
	while (tryagain < 10)
	{
		i = rand() % 8;
		if (is_free_space(game, &(moves[i]),
			game->v_chic.spawn_y, game->v_chic.spawn_x))
		{
			game->v_chic.spawn_y += moves[i].delta_row;
			game->v_chic.spawn_x += moves[i].delta_col;
			break ;
		}
		tryagain++;
	}
	game->v_chic.vc_dir = moves[i].direction;
}


void	enemy_movement(void *param)
{
	static int	i;
	t_game_state *game;

	game = (t_game_state *)param;
	i++;
	if (i % 45 == 0)
	{
		do_move(game, 0);
	}
	draw_map(game);
}
