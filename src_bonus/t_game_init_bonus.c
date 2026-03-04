/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:58:26 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/04 12:58:21 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include <stdio.h>

void	game_init(t_game_state *game, char **map, t_map_count m_inf)
{
	game_base_init(game, map, m_inf);
	game_win_init(game);
	game->player_dir = P_DOWN;
	game_image_ground_init(game);
	game_image_actor_init(game);
}

// ---- add fail for no texture
void	game_image_actor_init(t_game_state *game)
{
	game->img_p_up = load_image(game, "textures/stardew/krobusup.png");
	game->img_p_down = load_image(game, "textures/stardew/krobusdown.png");
	game->img_p_left = load_image(game, "textures/stardew/krobusleft.png");
	game->img_p_right = load_image(game, "textures/stardew/krobusright.png");
	game->v_chic.v_up = load_image(game, "textures/stardew/krobusup.png");
	game->v_chic.v_down = load_image(game, "textures/stardew/krobusdown.png");
	game->v_chic.v_left = load_image(game, "textures/stardew/krobusleft.png");
	game->v_chic.v_right = load_image(game, "textures/stardew/krobusright.png");
}

// ---- add fail for no texture
void	game_image_ground_init(t_game_state *game)
{
	game->img_lwall = load_image(game, "textures/stardew/leftwall.png");
	game->img_rwall = load_image(game, "textures/stardew/rightwall.png");
	game->img_twall = load_image(game, "textures/stardew/topwall.png");
	game->img_bwall = load_image(game, "textures/stardew/bottomwall.png");
	game->img_tlwall = load_image(game, "textures/stardew/topleft.png");
	game->img_trwall = load_image(game, "textures/stardew/topright.png");
	game->img_blwall = load_image(game, "textures/stardew/bottomleft.png");
	game->img_brwall = load_image(game, "textures/stardew/bottomright.png");
	game->img_1wall = load_image(game, "textures/stardew/1wall.png");
	game->img_floor = load_image(game, "textures/stardew/16_16.png");
	game->img_egg = load_image(game, "textures/stardew/egg.png");
	game->img_exit = load_image(game, "textures/stardew/exit.png");
}

void	game_win_init(t_game_state *game)
{
	game->win_info.title = "so_long";
	game->win_info.height = game->tile_size_px * game->map_info.map_height;
	game->win_info.width = game->tile_size_px * game->map_info.map_width;
	game->win = load_window(game);
}

void	game_base_init(t_game_state *game, char **map, t_map_count m_inf)
{
	ft_bzero(game, sizeof(t_game_state));
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_memory(map);
		free_map_info(&m_inf);
		ft_printf("Error\nmlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	game->map_info = m_inf;
	game->map = map;
	game->tile_size_px = TILE_SIZE_PIXEL;
}
