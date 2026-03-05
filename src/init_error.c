/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:19:28 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/05 13:09:54 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	destroy_on_error_cont(t_game_state *game)
{
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_p_down)
		mlx_destroy_image(game->mlx, game->img_p_down);
	if (game->img_p_left)
		mlx_destroy_image(game->mlx, game->img_p_left);
	if (game->img_p_up)
		mlx_destroy_image(game->mlx, game->img_p_up);
	if (game->img_p_right)
		mlx_destroy_image(game->mlx, game->img_p_right);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_context (game->mlx);
	return ;
}

void	destroy_on_error(t_game_state *game)
{
	if (game->img_1wall)
		mlx_destroy_image(game->mlx, game->img_1wall);
	if (game->img_blwall)
		mlx_destroy_image(game->mlx, game->img_blwall);
	if (game->img_brwall)
		mlx_destroy_image(game->mlx, game->img_brwall);
	if (game->img_bwall)
		mlx_destroy_image(game->mlx, game->img_blwall);
	if (game->img_tlwall)
		mlx_destroy_image(game->mlx, game->img_tlwall);
	if (game->img_trwall)
		mlx_destroy_image(game->mlx, game->img_trwall);
	if (game->img_twall)
		mlx_destroy_image(game->mlx, game->img_twall);
	if (game->img_lwall)
		mlx_destroy_image(game->mlx, game->img_lwall);
	if (game->img_rwall)
		mlx_destroy_image(game->mlx, game->img_rwall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_egg)
		mlx_destroy_image(game->mlx, game->img_egg);
	destroy_on_error_cont(game);
	return ;
}
