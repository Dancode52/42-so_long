/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/23 19:19:40 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// void	close_game(int key, void *mlx)
// {
// 	if (key == 41)
// 		mlx_loop_end((mlx_context)mlx);
// }

// void	window_close(int event, void *mlx)
// {
// 	(void)mlx;
// 	if (event == 0)
// 		mlx_loop_end((mlx_context)mlx);
// }

// typedef struct
// {
//     mlx_context mlx;
//     mlx_window win;
// } mlx_t;

// void update(void* param)
// {
//     static int i = 0;
//     mlx_t* mlx = (mlx_t*)param;

//     int color = 0;
//     for(int j = 0; i < 400; j++)
//     {
//         mlx_pixel_put(mlx->mlx, mlx->win, j, j, (mlx_color){ .rgba = 0xFF0000FF + (color << 8) });
//         mlx_pixel_put(mlx->mlx, mlx->win, 399 - j, j, (mlx_color){ .rgba = 0xFF0000FF });
//         color += (color < 255);
//     }
//     if(++i == 5000)
//     {
//         // here the rendering changes, the red put pixels
//         // we made in the main loop are erased
//         mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){ .rgba = 0x000000FF });
//     }
// }

int	gameshit(char **map, t_map_count map_info)
{
	mlx_context mlx;
	mlx_window win;
	mlx_window_create_info win_info = { 0 };
	mlx_image image;
	mlx_image image1;


	mlx = mlx_init();
	win_info.title = "Test_window";
	win_info.height = 32 * map_info.map_height;
	win_info.width = 32 * map_info.map_width;
	win = mlx_new_window(mlx, &win_info);

	mlx_set_fps_goal(mlx, 30);
	int imgw;
	int imgh;
	image = mlx_new_image_from_file(mlx, "textures/crate.png", &imgw, &imgh);

	int imgw1;
	int imgh1;
	image1 = mlx_new_image_from_file(mlx, "textures/lilfella.png", &imgw1, &imgh1);

    mlx_color pixels[40 * 40] = { 0 };
	mlx_color jpixels[40 * 40] = { 0 };
    int i = 0;
    for(int y = 0; y < 40; y++)
    {
        for(int x = 0; x < 40; x++, i++)
            pixels[i].rgba = 0xFF0000FF;
    }
	int j = 0;
    for(int y1 = 0; y1 < 40; y1++)
    {
        for(int x1 = 0; x1 < 40; x1++, j++)
            jpixels[j].rgba = 0x00FF00FF;
    }

	int t = 0;
	while (t < 7)
	{
		int tt = 0;
		while (tt < 19)
		{
			if (map[t][tt] == '1')
    			mlx_pixel_put_region(mlx, win, tt * 32, t *32, 32, 32, pixels); // Will put a square of 40x40 pixels at 100:100
			if (map[t][tt] == 'C')
				mlx_pixel_put_region(mlx, win, tt * 32, t *32, 32, 32, jpixels);
			if (map[t][tt] == 'E')
				mlx_put_image_to_window(mlx, win, image, tt * 32, t * 32);
			if (map[t][tt] == 'P')
				mlx_put_image_to_window(mlx, win, image1, tt * 32, t * 32);
			tt++;
		}
		t++;
	}

    mlx_loop(mlx);

	mlx_destroy_image(mlx, image);
    mlx_destroy_window(mlx, win);
    mlx_destroy_context(mlx);
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
