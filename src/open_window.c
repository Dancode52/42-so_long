/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/20 17:28:37 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	gameshit(void)
{
	mlx_context mlx;
	mlx_window_create_info info;
	mlx_window window;

	mlx = mlx_init();
	info.height = 500;
	info.width = 500;
	info.title = "how_long";
	window = mlx_new_window(mlx, &info);
	mlx_loop(mlx);

	mlx_destroy_window(mlx, window);
	mlx_destroy_context(mlx);

	free(mlx);
	return (1);
}
