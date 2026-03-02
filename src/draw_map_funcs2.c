/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_funcs2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:45:37 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/02 12:47:31 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_cauliflower(t_game_state *game, size_t row, size_t column)
{
	if ((column > 0 && column < game->map_info.map_width - 1)
		&& (row != 0 && row != game->map_info.map_height - 1)
		&& game->map[row][column] == '1')
		mlx_put_transformed_image_to_window(game->mlx, game->win,
			game->img_1wall, column * game->tile_size_px,
			row * game->tile_size_px, 4, 4, 0);
}

void	draw_collectible(t_game_state *game, size_t row, size_t column)
{
	size_t	p_col;
	size_t	p_row;

	p_col = game->map_info.player_pos[1];
	p_row = game->map_info.player_pos[0];
	if (game->map[p_row][p_col] == 'C')
	{
		game->map[p_row][p_col] = '0';
		game->map_info.collect_count--;
	}
	if (game->map[row][column] == 'C')
		mlx_put_transformed_image_to_window(game->mlx, game->win,
			game->img_egg, column * game->tile_size_px,
			row * game->tile_size_px, 4, 4, 0);
}

void	draw_exit(t_game_state *game, size_t row, size_t column)
{
	if (game->map[row][column] == 'E' && game->map_info.collect_count == 0)
		mlx_put_transformed_image_to_window(game->mlx, game->win,
			game->img_exit, column * game->tile_size_px,
			row * game->tile_size_px, 4, 4, 0);
}

void	draw_floor(t_game_state *game, size_t row, size_t column)
{
	mlx_put_transformed_image_to_window(game->mlx, game->win, game->img_floor,
		column * game->tile_size_px, row * game->tile_size_px, 4, 4, 0);
}

void	draw_step_count(t_game_state *game)
{
	char *tmp;
	char *c_itoa;

	tmp = NULL;
	c_itoa = ft_itoa(game->step_count);
	tmp = ft_strjoin("Step count: ", c_itoa);
	free(c_itoa);
	mlx_set_font_scale(game->mlx, "textures/stardew/svfontbold.ttf", 32);
	mlx_string_put(game->mlx, game->win, 1, 32,
		(mlx_color){.rgba = 0x000000FF}, tmp);
	free(tmp);
}
