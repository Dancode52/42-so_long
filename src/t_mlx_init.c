/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:16:12 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/26 09:20:49 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	t_mlx_init(t_mlx_and_stuff *t_mlx, char **map, t_map_count m_inf)
{
	t_mlx_base_init(t_mlx, map, m_inf);
	t_mlx_win_init(t_mlx);
	t_mlx_image_ground_init(t_mlx);
	t_mlx_image_player_init(t_mlx);
}


// ---- add fail for no texture
void	t_mlx_image_player_init(t_mlx_and_stuff *t_mlx)
{
	t_mlx->img_p_down = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/krobusdown.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_p_up = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/krobusup.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_p_left = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/krobusleft.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_p_right = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/krobusright.png", &t_mlx->img_width, &t_mlx->img_height);
}

// ---- add fail for no texture
void	t_mlx_image_ground_init(t_mlx_and_stuff *t_mlx)
{
	t_mlx->img_lwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/leftwall.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_rwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/rightwall.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_twall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/topwall.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_bwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/bottomwall.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_tlwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/topleft.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_trwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/topright.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_blwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/bottomleft.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_brwall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/bottomright.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_1wall = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/1wall.png", &t_mlx->img_width, &t_mlx->img_height);
	t_mlx->img_floor = mlx_new_image_from_file(t_mlx->mlx,
	 "textures/stardew/16_16.png", &t_mlx->img_width, &t_mlx->img_height);
}

void	t_mlx_win_init(t_mlx_and_stuff *t_mlx)
{
	t_mlx->win_info.title = "so_long";
	t_mlx->win_info.height = t_mlx->tile_side_px * t_mlx->map_info.map_height;
	t_mlx->win_info.width = t_mlx->tile_side_px * t_mlx->map_info.map_width;
	t_mlx->win = mlx_new_window(t_mlx->mlx, &t_mlx->win_info);
}

void	t_mlx_base_init(t_mlx_and_stuff *t_mlx, char **map, t_map_count m_inf)
{
	ft_bzero(t_mlx, sizeof(t_mlx_and_stuff));
	t_mlx->map_info = m_inf;
	t_mlx->mlx = mlx_init();
	t_mlx->map = map;
	t_mlx->tile_side_px = 64;
}
