/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/23 17:28:25 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	close_game(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end((mlx_context)mlx);
}

void	window_close(int event, void *mlx)
{
	(void)mlx;
	if (event == 0)
		mlx_loop_end((mlx_context)mlx);
}

typedef struct
{
    mlx_context mlx;
    mlx_window win;
} mlx_t;

void update(void* param)
{
    static int i = 0;
    mlx_t* mlx = (mlx_t*)param;

    int color = 0;
    for(int j = 0; i < 400; j++)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, j, j, (mlx_color){ .rgba = 0xFF0000FF + (color << 8) });
        mlx_pixel_put(mlx->mlx, mlx->win, 399 - j, j, (mlx_color){ .rgba = 0xFF0000FF });
        color += (color < 255);
    }
    if(++i == 5000)
    {
        // here the rendering changes, the red put pixels
        // we made in the main loop are erased
        mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){ .rgba = 0x000000FF });
    }
}

int	gameshit(void)
{
    mlx_t mlx;

    mlx.mlx = mlx_init();

    mlx_window_create_info info = { 0 };
    info.title = "Hello World!";
    info.width = 400;
    info.height = 400;
    mlx.win = mlx_new_window(mlx.mlx, &info);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            // this will be rendered until we call `mlx_clear_window`
            mlx_pixel_put(mlx.mlx, mlx.win, i, j, (mlx_color){ .rgba = 0xFF0000FF });
        }
    }

    mlx_add_loop_hook(mlx.mlx, update, &mlx);
    mlx_loop(mlx.mlx);

    mlx_destroy_window(mlx.mlx, mlx.win);
    mlx_destroy_context(mlx.mlx);
	return (0);
}
    // mlx_context mlx = mlx_init();

    // mlx_window_create_info info = { 0 };
    // info.title = "Hello World!";
    // info.width = 400;
    // info.height = 400;
    // mlx_window win = mlx_new_window(mlx, &info);

    // int img_width;
    // int img_height;
    // mlx_image img = mlx_new_image_from_file(mlx, "textures/mlxtest.jpeg", &img_width, &img_height);

	// mlx_put_image_to_window(mlx, win, img, 0, 0);

	// mlx_on_event(mlx, win, MLX_KEYDOWN, close_game, mlx);
	// mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_close, mlx);

    // mlx_loop(mlx);

    // // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
    // mlx_destroy_image(mlx, img);
    // mlx_destroy_window(mlx, win);
    // mlx_destroy_context(mlx);


// {
//     mlx_context mlx = mlx_init();

//     mlx_window_create_info window_info = { 0 };
//     window_info.title = "Hello World!";
//     window_info.width = 400;
//     window_info.height = 400;
//     mlx_window win = mlx_new_window(mlx, &window_info);

//     mlx_image target = mlx_new_image(mlx, 100, 100);

//     mlx_window_create_info target_info = { 0 };
//     target_info.render_target = target;
//     mlx_window target_win = mlx_new_window(mlx, &target_info);


//         // All of this will be rendered in `target`
// 	mlx_clear_window(mlx, target_win, (mlx_color){ .rgba = 0xC16868FF });
// 	mlx_string_put(mlx, target_win, 10, 10, (mlx_color){ .rgba = 0xFF2066FF }, "text");
// 	mlx_pixel_put(mlx, target_win, 20, 40, (mlx_color){ .rgba = 0xFF0000FF });


//     mlx_put_image_to_window(mlx, win, target, 10, 10); // Render the target to the real window

// 	sleep(10);
//     mlx_destroy_window(mlx, target_win);
//     mlx_destroy_image(mlx, target);

//     mlx_destroy_window(mlx, win);

//     mlx_destroy_context(mlx);
// 	return (0);
// }
// {
// 	mlx_context mlx = mlx_init();

// 	mlx_window_create_info info = { 0 };
// 	info.title = "how_long";
// 	info.height = 500;
// 	info.width = 500;

// 	mlx_window window = mlx_new_window(mlx, &info);

// 	mlx_loop(mlx);

// 	// mlx_destroy_window(mlx, window);
// 	// mlx_destroy_context(mlx);

// 	// free(mlx);
// 	return (1);
// }
