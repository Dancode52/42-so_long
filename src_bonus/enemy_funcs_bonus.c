/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:58:57 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/04 16:08:12 by dlanehar         ###   ########.fr       */
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

void	enemy_movement(void *param)
{
	static int	i;
	t_game_state *game;
	int	dir_to_take;

	game = (t_game_state *)param;
	i++;
	if (i % 60 == 0)
	{
		dir_to_take = rand() % 4;
		if (dir_to_take == 0)
			game->v_chic.spawn_x += 1;
		if (dir_to_take == 1)
			game->v_chic.spawn_x -= 1;
		if (dir_to_take == 2)
			game->v_chic.spawn_y -= 1;
		if (dir_to_take == 3)
			game->v_chic.spawn_y -= 1;
	}
	draw_enemy(game);
}

void	do_move(t_game_state *game, int dir)
{
	int i;
	t_move	moves;

	moves = init_moves()
	i = 0;
	while (i < 8)
	{
		if ((int)moves[i].key == in_key)
		{
			if (is_free_space(game, &(moves[i])))
			{
				game->map_info.player_pos[0] += moves[i].delta_row;
				game->map_info.player_pos[1] += moves[i].delta_col;
				game->step_count++;
			}
			game->player_dir = moves[i].direction;
			break ;
		}
		i++;
	}
}
