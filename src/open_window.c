/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/28 00:18:04 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_map(char **map, t_game_state game);

void	exit_event(int key, void *param)
{
	if (key == 41 || key == 0)
		mlx_loop_end((mlx_context)param);
}

#include <stdio.h>

void	move_right(int key, void *param)
{
	t_game_state *game = (t_game_state *)param;
	size_t	current_pos;

	current_pos = game->map_info.player_pos[1];
	printf("player pos[0] %zu\nplayer pos[1] %zu\n",game->map_info.player_pos[0], current_pos);
	if (key == 7 || key == 79)
	{
		ft_printf("pressed\n");
		if (game->map[game->map_info.player_pos[0]][current_pos + 1] == '1')
		{
			ft_printf("Wall!\n");
			return ;
		}
		//mlx_put_image_to_window(mlx.mlx, mlx.win, mlx->img_floor)
		game->map[game->map_info.player_pos[0]][current_pos] = '0';
	//	current_pos += 1;
		game->step_count += 1;
		game->map[game->map_info.player_pos[0]][current_pos + 1] = 'P';

		printf("Step count: %zu\n", game->step_count);
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_floor, current_pos * game->tile_size_px, game->map_info.player_pos[0] * game->tile_size_px, 4, 4, 0);
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_p_right, (current_pos + 1) * game->tile_size_px, game->map_info.player_pos[0] * game->tile_size_px - 32, 4, 4, 0);
	//	mlx_pixel_put_region(mlx->mlx, mlx->win,
	//	 mlx->map_info.player_pos[1] * game.tile_size_px,
	//	 mlx->map_info.player_pos[0] * game.tile_size_px, game.tile_size_px, game.tile_size_px, mlx->colours.p_colour);
	}
	//draw_map(mlx->map, *mlx);
	game->map_info.player_pos[1]++;
}

void	draw_l_r_walls(char **map, t_game_state game, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_lwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
	if (column == game.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_rwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
}

void	draw_t_l_r_walls(char **map, t_game_state game, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_tlwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
	if (column == game.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_trwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
}

void	draw_b_l_r_walls(char **map, t_game_state game, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_blwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
	if (column == game.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_brwall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
}

void	draw_player(t_game_state game)
{
	size_t row;
	size_t column;

	row = game.map_info.player_pos[0];
	column = game.map_info.player_pos[1];
	mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_p_left, column * game.tile_size_px, row * game.tile_size_px - 32, 4, 4, 0);
}

void	draw_map(char **map, t_game_state game)
{
	size_t row = 0;
	while (row < game.map_info.map_height)
	{
		size_t column = 0;
		while (column < game.map_info.map_width)
		{
			mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_floor, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
			if (row == 0 && (column == 0 || column == game.map_info.map_width - 1))
				draw_t_l_r_walls(map, game, row, column);
			if ((row > 0 && row < game.map_info.map_height) && (column == 0 || column == game.map_info.map_width - 1))
				draw_l_r_walls(map, game, row, column);
			if (row == game.map_info.map_height - 1 && (column == 0 || column == game.map_info.map_width - 1))
				draw_b_l_r_walls(map, game, row, column);
			if ((column > 0 && column < game.map_info.map_width - 1) && map[row][column] == '1')
    			mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_1wall, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
			// if (map[row][column] == '0')
			// 	mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_floor, column * game.tile_size_px, row * game.tile_size_px, 4, 4, 0);
			if (map[row][column] == 'C')
				mlx_pixel_put_region(game.mlx, game.win, column * game.tile_size_px,
				 row *game.tile_size_px, game.tile_size_px, game.tile_size_px, game.colours.c_colour);
			if (map[row][column] == 'E')
				mlx_pixel_put_region(game.mlx, game.win, column * game.tile_size_px,
				 row *game.tile_size_px, game.tile_size_px, game.tile_size_px, game.colours.e_colour);
			// if (map[row][column] == 'P')
			// 	mlx_put_transformed_image_to_window(game.mlx, game.win, game.img_p_left, column * game.tile_size_px, row * game.tile_size_px - 32, 4, 4, 0);
			column++;
		}
		row++;
	}
	draw_player(game);
}

void	destroy_all_image(t_game_state game)
{
	mlx_destroy_image(game.mlx, game.img_blwall);
	mlx_destroy_image(game.mlx, game.img_brwall);
	mlx_destroy_image(game.mlx, game.img_tlwall);
	mlx_destroy_image(game.mlx, game.img_trwall);
	mlx_destroy_image(game.mlx, game.img_lwall);
	mlx_destroy_image(game.mlx, game.img_rwall);
	mlx_destroy_image(game.mlx, game.img_twall);
	mlx_destroy_image(game.mlx, game.img_bwall);
	mlx_destroy_image(game.mlx, game.img_1wall);
	mlx_destroy_image(game.mlx, game.img_floor);
	mlx_destroy_image(game.mlx, game.img_p_down);
	mlx_destroy_image(game.mlx, game.img_p_up);
	mlx_destroy_image(game.mlx, game.img_p_right);
	mlx_destroy_image(game.mlx, game.img_p_left);
}
//transparency test
char **arraycopy(char **map)
{
	int height;
	char **dup;

	height = 0;
	while (map[height])
		height++;
	dup = ft_calloc(height + 1, sizeof(char *));
	height = 0;
	while (map[height])
	{
		dup[height] = ft_strdup(map[height]);
		height++;
	}
	return (dup);
}
void make0(char **dup)
{
	int i;
	int j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			if (dup[i][j] == 'P' || dup[i][j] ==  'E' || dup[i][j] ==  'C')
				dup[i][j] = '0';
			j++;
		}
		i++;
	}
}
//end transparency test

int	run_game(char **map, t_map_count map_info)
{
	t_game_state game;
	//char **map1; //transparency test

	game_init(&game, map, map_info);
//	map1 = arraycopy(map);
//	make0(map1);

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


	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, move_right, &game);
	mlx_on_event(game.mlx, game.win, MLX_KEYDOWN, exit_event, game.mlx);
	mlx_on_event(game.mlx, game.win, MLX_WINDOW_EVENT, exit_event, game.mlx);

//	printmap(map1);
//	draw_map(map1, game);
	draw_map(map, game);
    mlx_loop(game.mlx);

	destroy_all_image(game);
    mlx_destroy_window(game.mlx, game.win);
    mlx_destroy_context(game.mlx);
	free_memory(map1);
	return (0);
}
