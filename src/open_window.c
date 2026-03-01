/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/01 17:21:27 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/so_long.h"

void	exit_event(int key, void *param)
{
	if (key == 41 || key == 0)
		mlx_loop_end((mlx_context)param);
}

t_movement	*init_moves(void)
{
	static t_movement	moves[8];

	moves[0] = (t_movement){W_KEY, P_UP, -1, 0};
	moves[1] = (t_movement){UP_KEY, P_UP, -1, 0};
	moves[2] = (t_movement){A_KEY, P_LEFT, 0, -1};
	moves[3] = (t_movement){LEFT_KEY, P_LEFT, 0, -1};
	moves[4] = (t_movement){S_KEY, P_DOWN, 1, 0};
	moves[5] = (t_movement){DOWN_KEY, P_DOWN, 1, 0};
	moves[6] = (t_movement){D_KEY, P_RIGHT, 0, 1};
	moves[7] = (t_movement){RIGHT_KEY, P_RIGHT, 0, 1};
	return (moves);
}

int	is_free_space(t_game_state *game, t_movement *moves)
{
	size_t col;
	size_t row;

	col = game->map_info.player_pos[1];
	row = game->map_info.player_pos[0];
	if (game->map[row + moves->delta_row][col + moves->delta_col] == '1')
		return (0);
	return 1;
}
void	move_player(int in_key, void *param)
{
	t_game_state *game;
	t_movement	*moves;
	int	i;

	game = (t_game_state *)param;
	moves = init_moves();
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
	ft_printf("Steps taken: %i\n", (int)game->step_count);
	draw_map(game);
	return ;
}


// void	move_player(int in_key, void *param)
// {
// 	t_game_state *game = (t_game_state *)param;
// 	t_movement	*moves;
// 	int	i = 0;

// 	moves = init_moves();
// 	while (i < 8)
// 	{
// 		if ((int)moves[i].key == in_key)
// 		{
// 			if (is_free_space(game, &(moves[i])))
// 			{
// 				game->map_info.player_pos[0] += moves[i].delta_row;
// 				game->map_info.player_pos[1] += moves[i].delta_col;
// 				game->step_count++;
// 			}
// 			game->player_dir = moves[i].direction;
// 			break ;
// 		}
// 		i++;
// 	}
// 	printf("Steps taken: %zu\n", game->step_count);
// 	draw_map(game);
// 	return ;
// }

// void	move_player(int key, void *param)
// {
// 	t_game_state *game = (t_game_state *)param;
// 	size_t	column;
// 	size_t	row;


// 	column = game->map_info.player_pos[1];
// 	row = game->map_info.player_pos[0];
// 	if (key == 7 || key == 79)
// 	{
// 		game->player_dir = P_RIGHT;
// 		if (column + 1 >= game->map_info.map_width)
// 			return ;
// 		if (game->map[row][column + 1] == '1')
// 			return ;
// 		game->map_info.player_pos[1] += 1;
// 	}
// 	if (key == 4 || key == 80)
// 	{
// 		game->player_dir = P_LEFT;
// 		if (game->map[row][column - 1] == '1')
// 			return ;
// 		game->map_info.player_pos[1] -= 1;
// 	}
// 	if (key == 26 || key == 82)
// 	{
// 		game->player_dir = P_UP;
// 		if (game->map[row - 1][column] == '1')
// 			return ;
// 		game->map_info.player_pos[0] -= 1;
// 	}
// 	if (key == 22 || key == 81)
// 	{
// 		game->player_dir = P_DOWN;
// 		if (game->map[row + 1][column] == '1')
// 			return ;
// 		game->map_info.player_pos[0] += 1;
// 	}
// 	game->step_count++;
// 	printf("step count is %zu\n", game->step_count);
// 	mlx_clear_window(game->mlx, game->win, (mlx_color){ .rgba = 0x000000FF });
// 	draw_map(game);
// }

void	draw_map(t_game_state *game)
{
	size_t row = 0;
	mlx_clear_window(game->mlx, game->win, (mlx_color){ .rgba = 0x000000FF });
	while (row < game->map_info.map_height)
	{
		size_t column = 0;
		while (column < game->map_info.map_width)
		{
			mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_floor, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
			if (row == 0 && (column == 0 || column == game->map_info.map_width - 1))
				draw_t_l_r_walls(game, row, column);
			if ((row > 0 && row < game->map_info.map_height - 1) && (column == 0 || column == game->map_info.map_width - 1))
				draw_l_r_walls(game, row, column);
			if (row == game->map_info.map_height - 1 && (column == 0 || column == game->map_info.map_width - 1))
				draw_b_l_r_walls(game, row, column);
			if ((row == 0 || row == game->map_info.map_height - 1) && (column > 0 && column < game->map_info.map_width - 1))
				draw_t_b_walls(game, row, column);
			if ((column > 0 && column < game->map_info.map_width - 1) && (row != 0 && row != game->map_info.map_height - 1) && game->map[row][column] == '1')
    			mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_1wall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
			if (game->map[row][column] == 'C')
				mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_exit, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
			if (game->map[row][column] == 'E')
				mlx_pixel_put_region(game->mlx, game->win, column * game->tile_size_px,
				 row *game->tile_size_px, game->tile_size_px, game->tile_size_px, game->colours.e_colour);
			column++;
		}
		row++;
	}
	draw_player(game);
	printf("row = %zu, col = %zu\n", game->map_info.player_pos[0], game->map_info.player_pos[1]);
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

int	run_game(char **map, t_map_count map_info)
{
	t_game_state game;

	game_init(&game, map, map_info);

	mlx_set_fps_goal(game.mlx, 30);

	ft_bzero(&game.colours, sizeof(t_colours));
	size_t i = 0;
	while (i < (game.tile_size_px * game.tile_size_px))
		game.colours.p_colour[i++].rgba = 0x0000FFFF;
	i = 0;
	while (i < (game.tile_size_px * game.tile_size_px))
		game.colours.c_colour[i++].rgba = 0xf9d624FF;
	i = 0;
	while (i < (game.tile_size_px * game.tile_size_px))
		game.colours.wall_colour[i++].rgba = 0xFF0000FF;
	i = 0;
	while (i < (game.tile_size_px * game.tile_size_px))
		game.colours.e_colour[i++].rgba = 0xa76a22FF;
	i = 0;

	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, move_player, &game);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, exit_event, game.mlx);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, exit_event, game.mlx);

	printf("game ptr = %p\n", (void *)(&game));
	printf("map  ptr = %p\n", (void *)game.map);
	printmap(map);
	printf("map_width = %zu\n", game.map_info.map_width);
	printf("map_height = %zu\n", game.map_info.map_height);
	draw_map(&game);
    mlx_loop(game.mlx);

	destroy_all_image(&game);
    mlx_destroy_window(game.mlx, game.win);
    mlx_destroy_context(game.mlx);
	return (0);
}
