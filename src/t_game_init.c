/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:16:12 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/26 09:32:00 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	game_init(t_game_state *game, char **map, t_map_count m_inf)
{
	game_base_init(game, map, m_inf);
	game_win_init(game);
	game_image_ground_init(game);
	game_image_player_init(game);
}

// ---- add fail for no texture
void	game_image_player_init(t_game_state *game)
{
	game->img_p_down = mlx_new_image_from_file(game->mlx,
			"textures/stardew/krobusdown.png", &game->img_w, &game->img_h);
	game->img_p_up = mlx_new_image_from_file(game->mlx,
			"textures/stardew/krobusup.png", &game->img_w, &game->img_h);
	game->img_p_left = mlx_new_image_from_file(game->mlx,
			"textures/stardew/krobusleft.png", &game->img_w, &game->img_h);
	game->img_p_right = mlx_new_image_from_file(game->mlx,
			"textures/stardew/krobusright.png", &game->img_w, &game->img_h);
}

// ---- add fail for no texture
void	game_image_ground_init(t_game_state *game)
{
	game->img_lwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/leftwall.png", &game->img_w, &game->img_h);
	game->img_rwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/rightwall.png", &game->img_w, &game->img_h);
	game->img_twall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/topwall.png", &game->img_w, &game->img_h);
	game->img_bwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/bottomwall.png", &game->img_w, &game->img_h);
	game->img_tlwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/topleft.png", &game->img_w, &game->img_h);
	game->img_trwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/topright.png", &game->img_w, &game->img_h);
	game->img_blwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/bottomleft.png", &game->img_w, &game->img_h);
	game->img_brwall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/bottomright.png", &game->img_w, &game->img_h);
	game->img_1wall = mlx_new_image_from_file(game->mlx,
			"textures/stardew/1wall.png", &game->img_w, &game->img_h);
	game->img_floor = mlx_new_image_from_file(game->mlx,
			"textures/stardew/16_16.png", &game->img_w, &game->img_h);
}

void	game_win_init(t_game_state *game)
{
	game->win_info.title = "so_long";
	game->win_info.height = game->tile_size_px * game->map_info.map_height;
	game->win_info.width = game->tile_size_px * game->map_info.map_width;
	game->win = mlx_new_window(game->mlx, &game->win_info);
}

void	game_base_init(t_game_state *game, char **map, t_map_count m_inf)
{
	ft_bzero(game, sizeof(t_game_state));
	game->map_info = m_inf;
	game->mlx = mlx_init();
	game->map = map;
	game->tile_size_px = 64;
}
