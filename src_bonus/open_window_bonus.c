/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/04 15:47:35 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/so_long_bonus.h"

void	exit_event(int key, void *param)
{
	if (key == 41 || key == 0)
		mlx_loop_end((mlx_context)param);
}

void	draw_map(t_game_state *game)
{
	size_t	row;
	size_t	column;

	row = 0;
	mlx_clear_window(game->mlx, game->win, (mlx_color){.rgba = 0x000000FF});
	while (row < game->map_info.map_height)
	{
		column = 0;
		while (column < game->map_info.map_width)
		{
			draw_floor(game, row, column);
			draw_t_l_r_walls(game, row, column);
			draw_l_r_walls(game, row, column);
			draw_b_l_r_walls(game, row, column);
			draw_t_b_walls(game, row, column);
			draw_cauliflower(game, row, column);
			draw_collectible(game, row, column);
			draw_exit(game, row, column);
			column++;
		}
		row++;
	}
	draw_player(game);
	draw_enemy(game);
	draw_step_count(game);
}

void	destroy_all_image(t_game_state *game)
{
	mlx_destroy_image(game->mlx, game->img_blwall);
	mlx_destroy_image(game->mlx, game->img_brwall);
	mlx_destroy_image(game->mlx, game->img_tlwall);
	mlx_destroy_image(game->mlx, game->img_trwall);
	mlx_destroy_image(game->mlx, game->img_lwall);
	mlx_destroy_image(game->mlx, game->img_rwall);
	mlx_destroy_image(game->mlx, game->img_twall);
	mlx_destroy_image(game->mlx, game->img_bwall);
	mlx_destroy_image(game->mlx, game->img_1wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_p_down);
	mlx_destroy_image(game->mlx, game->img_p_up);
	mlx_destroy_image(game->mlx, game->img_p_right);
	mlx_destroy_image(game->mlx, game->img_p_left);
	mlx_destroy_image(game->mlx, game->img_egg);
	mlx_destroy_image(game->mlx, game->img_exit);
}

void	completion_check(void *param)
{
	t_game_state	*game;
	size_t			p_col;
	size_t			p_row;

	game = (t_game_state *)param;
	p_col = game->map_info.player_pos[1];
	p_row = game->map_info.player_pos[0];
	if (game->map_info.collect_count == 0 && game->map[p_row][p_col] == 'E')
	{
		ft_printf("--- YOU WIN! --- \n");
		mlx_loop_end(game->mlx);
	}
}

int	run_game(char **map, t_map_count map_info)
{
	t_game_state	game;

	game_init(&game, map, map_info);
	get_enemy_spawn(&game);
	mlx_set_fps_goal(game.mlx, 60);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, move_player, &game);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, exit_event, game.mlx);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, exit_event, game.mlx);
	draw_map(&game);
	mlx_add_loop_hook(game.mlx, enemy_movement, &game);
	mlx_add_loop_hook(game.mlx, completion_check, &game);
	mlx_loop(game.mlx);
	destroy_all_image(&game);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_context(game.mlx);
	return (0);
}
