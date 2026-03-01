/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 11:24:38 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/01 17:03:53 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_t_l_r_walls(t_game_state *game, size_t row, size_t column)
{
	if (column == 0)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_tlwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
	if (column == game->map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_trwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void	draw_b_l_r_walls(t_game_state *game, size_t row, size_t column)
{
	if (column == 0)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_blwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
	if (column == game->map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_brwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void	draw_l_r_walls(t_game_state *game, size_t row, size_t column)
{
	if (column == 0)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_lwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
	if (column == game->map_info.map_width - 1)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_rwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void draw_t_b_walls(t_game_state *game, size_t row, size_t column)
{
	if (row == 0)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_twall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
	if (row == game->map_info.map_height - 1)
		mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_bwall, column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void	draw_player(t_game_state *game)
{
	size_t row;
	size_t column;
	mlx_image	sprite;

	sprite = game->img_p_down;
	row = game->map_info.player_pos[0];
	column = game->map_info.player_pos[1];
	if (game->player_dir == P_RIGHT)
		sprite = game->img_p_right;
	if (game->player_dir == P_LEFT)
		sprite = game->img_p_left;
	if (game->player_dir == P_UP)
		sprite = game->img_p_up;
	if (game->player_dir == P_DOWN)
		sprite = game->img_p_down;

	mlx_put_transformed_image_to_window(game->mlx, game->win, sprite, column * game->tile_size_px, row * game->tile_size_px - 32, 4, 4, 0);
}
