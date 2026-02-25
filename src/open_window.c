// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   open_window.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/20 14:05:41 by dlanehar          #+#    #+#             */
// /*   Updated: 2026/02/24 11:00:20 by dlanehar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */



#include "../headers/so_long.h"

typedef struct s_colours
{
	mlx_color	p_colour[64 * 64];
	mlx_color	wall_colour[64 * 64];
	mlx_color	c_colour[64 * 64];
	mlx_color	e_colour[64 * 64];
	mlx_color	open_e_colour[64 * 64];
}	t_colours;

typedef struct s_mlx_and_stuff
{
	mlx_context mlx;
	mlx_window_create_info win_info;
	mlx_window win;
	int img_width;
	int img_height;
	mlx_image	img_lwall;
	mlx_image	img_rwall;
	mlx_image	img_twall;
	mlx_image	img_bwall;
	mlx_image	img_tlwall;
	mlx_image	img_trwall;
	mlx_image	img_blwall;
	mlx_image	img_brwall;
	mlx_image	img_1wall;
	mlx_image	img_floor;
	mlx_image	img_p_down;
	mlx_image	img_p_up;
	mlx_image	img_p_left;
	mlx_image	img_p_right;
	t_map_count map_info;
	t_colours colours;
	size_t	step_count;
	char **map;
} t_mlx_and_stuff;

void	draw_map(char **map, t_mlx_and_stuff t_mlx);

// #include "../headers/so_long.h"

// // void	close_game(int key, void *mlx)
// // {
// // 	if (key == 41)
// // 		mlx_loop_end((mlx_context)mlx);
// // }

// // void	window_close(int event, void *mlx)
// // {
// // 	(void)mlx;
// // 	if (event == 0)
// // 		mlx_loop_end((mlx_context)mlx);
// // }

// // typedef struct
// // {
// //     mlx_context mlx;
// //     mlx_window win;
// // } mlx_t;

// // void update(void* param)
// // {
// //     static int i = 0;
// //     mlx_t* mlx = (mlx_t*)param;

// //     int color = 0;
// //     for(int j = 0; i < 400; j++)
// //     {
// //         mlx_pixel_put(mlx->mlx, mlx->win, j, j, (mlx_color){ .rgba = 0xFF0000FF + (color << 8) });
// //         mlx_pixel_put(mlx->mlx, mlx->win, 399 - j, j, (mlx_color){ .rgba = 0xFF0000FF });
// //         color += (color < 255);
// //     }
// //     if(++i == 5000)
// //     {
// //         // here the rendering changes, the red put pixels
// //         // we made in the main loop are erased
// //         mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){ .rgba = 0x000000FF });
// //     }
// // }

// typedef struct s_colours
// {
// 	mlx_color	p_colour[32 * 32];
// 	mlx_color	wall_colour[32 * 32];
// 	mlx_color	c_colour[32 * 32];
// 	mlx_color	e_colour[32 * 32];
// 	mlx_color	open_e_colour[32 * 32];
// }	t_colours;

// typedef struct s_mlx_and_stuff
// {
// 	mlx_context mlx;
// 	mlx_window_create_info win_info;
// 	mlx_window win;
// 	t_map_count map_info;
// 	t_colours colours;
// 	char **map;
// } t_mlx_and_stuff;

// void	exit_event(int key, void *param)
// {
// 	if (key == 41 || key == 0)
// 		mlx_loop_end((mlx_context)param);
// 	// if (key == 87 || key == 38) //w or up
// 	// 	mlx_pixel_put_region(mlx, win, tt * 32, t *32, 32, 32, colours.p_colour);
// 	// if (key == 65 || key == 37) //a or left
// 	// if (key == 83 || key == 40) //s or down
// 	// if (key == 68 || key == 39) //d or right
// }

// void	move_right(int key, void *param)
// {
// 	t_mlx_and_stuff *mlx = (t_mlx_and_stuff *)param;
// 	if (key == 68 || key == 39)
// 		mlx->map[mlx->map_info.player_pos[0]] += 1;
// 	if (mlx->map[mlx->map_info.player_pos[0]][mlx->map_info.player_pos[1]] == 'P')
// 		mlx_pixel_put_region(mlx->mlx, mlx->win, mlx->map_info.player_pos[0] * 32, mlx->map_info.player_pos[1] *32, 32, 32, mlx->colours.p_colour);
// }

// void	right_key_update(void *param)
// {
// 	t_mlx_and_stuff *mlx = (t_mlx_and_stuff *)param;
// 	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, move_right, mlx);
// }


// int	gameshit(char **map, t_map_count map_info)
// {
// //	mlx_context mlx;
// //	mlx_window win;
// //	mlx_window_create_info win_info = { 0 };
// //	mlx_image image;
// //	mlx_image image1;
// //	t_colours colours;

// 	t_mlx_and_stuff t_mlx;
// 	t_mlx.map_info = map_info;
// 	t_mlx.mlx = mlx_init();
// 	t_mlx.map = map;

// 	//t_mlx.win_info = {0};
// 	ft_bzero(&t_mlx.win_info, sizeof(mlx_window_create_info));
// 	t_mlx.win_info.title = "Test_window";
// 	t_mlx.win_info.height = 32 * map_info.map_height;
// 	t_mlx.win_info.width = 32 * map_info.map_width;

// 	//mlx = mlx_init();
// 	t_mlx.win = mlx_new_window(t_mlx.mlx, &t_mlx.win_info);
// //	win = mlx_new_window(mlx, &win_info);

// 	mlx_set_fps_goal(t_mlx.mlx, 30);

// 	ft_bzero(&t_mlx.colours, sizeof(t_colours));

// 	int i = 0;
// 	while (i < (32 * 32))
// 		t_mlx.colours.p_colour[i++].rgba = 0x0000FFFF;
// 	i = 0;
// 	while (i < (32 * 32))
// 		t_mlx.colours.c_colour[i++].rgba = 0xf9d624FF;
// 	i = 0;
// 	while (i < (32 * 32))
// 		t_mlx.colours.wall_colour[i++].rgba = 0xFF0000FF;
// 	i = 0;
// 	while (i < (32 * 32))
// 		t_mlx.colours.e_colour[i++].rgba = 0xa76a22FF;
// 	i = 0;
// 	// while (i < (32 * 32))
// 	// 	t_mlx.colours.p_colour[i++].rgba = 0x0000FFFF;
// 	// int imgw;
// 	// int imgh;
// 	// image = mlx_new_image_from_file(mlx, "textures/crate.png", &imgw, &imgh);

// 	// int imgw1;
// 	// int imgh1;
// 	// image1 = mlx_new_image_from_file(mlx, "textures/lilfella.png", &imgw1, &imgh1);

//     // mlx_color pixels[40 * 40] = { 0 };
// 	// mlx_color jpixels[40 * 40] = { 0 };
//     // int i = 0;
//     // for(int y = 0; y < 40; y++)
//     // {
//     //     for(int x = 0; x < 40; x++, i++)
//     //         pixels[i].rgba = 0xFF0000FF;
//     // }
// 	// int j = 0;
//     // for(int y1 = 0; y1 < 40; y1++)
//     // {
//     //     for(int x1 = 0; x1 < 40; x1++, j++)
//     //         jpixels[j].rgba = 0x00FF00FF;
//     // }

// 	int t = 0;
// 	while (t < 7)
// 	{
// 		int tt = 0;
// 		while (tt < 19)
// 		{
// 			if (map[t][tt] == '1')
//     			mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, tt * 32, t *32, 32, 32, t_mlx.colours.wall_colour); // Will put a square of 40x40 pixels at 100:100
// 			if (map[t][tt] == 'C')
// 				mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, tt * 32, t *32, 32, 32, t_mlx.colours.c_colour);
// 			if (map[t][tt] == 'E')
// 				mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, tt * 32, t *32, 32, 32, t_mlx.colours.e_colour);
// 			if (map[t][tt] == 'P')
// 				mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, tt * 32, t *32, 32, 32, t_mlx.colours.p_colour);
// 			tt++;
// 		}
// 		t++;
// 	}
// 	mlx_on_event(t_mlx.mlx, t_mlx.win, MLX_KEYDOWN, exit_event, &t_mlx);
// 	mlx_on_event(t_mlx.mlx, t_mlx.win, MLX_WINDOW_EVENT, exit_event, t_mlx.mlx);

// 	mlx_add_loop_hook(t_mlx.mlx, right_key_update, &t_mlx);
//     mlx_loop(t_mlx.mlx);

// 	//mlx_destroy_image(mlx, image);
//     mlx_destroy_window(t_mlx.mlx, t_mlx.win);
//     mlx_destroy_context(t_mlx.mlx);
// 	return (0);
// }
//     // mlx_context mlx = mlx_init();

//     // mlx_window_create_info info = { 0 };
//     // info.title = "Hello World!";
//     // info.width = 400;
//     // info.height = 400;
//     // mlx_window win = mlx_new_window(mlx, &info);

//     // int img_width;
//     // int img_height;
//     // mlx_image img = mlx_new_image_from_file(mlx, "textures/mlxtest.jpeg", &img_width, &img_height);

// 	// mlx_put_image_to_window(mlx, win, img, 0, 0);

// 	// mlx_on_event(mlx, win, MLX_KEYDOWN, close_game, mlx);
// 	// mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_close, mlx);

//     // mlx_loop(mlx);

//     // // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
//     // mlx_destroy_image(mlx, img);
//     // mlx_destroy_window(mlx, win);
//     // mlx_destroy_context(mlx);


// // {
// //     mlx_context mlx = mlx_init();

// //     mlx_window_create_info window_info = { 0 };
// //     window_info.title = "Hello World!";
// //     window_info.width = 400;
// //     window_info.height = 400;
// //     mlx_window win = mlx_new_window(mlx, &window_info);

// //     mlx_image target = mlx_new_image(mlx, 100, 100);

// //     mlx_window_create_info target_info = { 0 };
// //     target_info.render_target = target;
// //     mlx_window target_win = mlx_new_window(mlx, &target_info);


// //         // All of this will be rendered in `target`
// // 	mlx_clear_window(mlx, target_win, (mlx_color){ .rgba = 0xC16868FF });
// // 	mlx_string_put(mlx, target_win, 10, 10, (mlx_color){ .rgba = 0xFF2066FF }, "text");
// // 	mlx_pixel_put(mlx, target_win, 20, 40, (mlx_color){ .rgba = 0xFF0000FF });


// //     mlx_put_image_to_window(mlx, win, target, 10, 10); // Render the target to the real window

// // 	sleep(10);
// //     mlx_destroy_window(mlx, target_win);
// //     mlx_destroy_image(mlx, target);

// //     mlx_destroy_window(mlx, win);

// //     mlx_destroy_context(mlx);
// // 	return (0);
// // }
// // {
// // 	mlx_context mlx = mlx_init();

// // 	mlx_window_create_info info = { 0 };
// // 	info.title = "how_long";
// // 	info.height = 500;
// // 	info.width = 500;

// // 	mlx_window window = mlx_new_window(mlx, &info);

// // 	mlx_loop(mlx);

// // 	// mlx_destroy_window(mlx, window);
// // 	// mlx_destroy_context(mlx);

// // 	// free(mlx);
// // 	return (1);
// // }

void	exit_event(int key, void *param)
{
	if (key == 41 || key == 0)
		mlx_loop_end((mlx_context)param);
}

#include <stdio.h>

// void	move_right(int key, void *param)
// {
// 	t_mlx_and_stuff *mlx = (t_mlx_and_stuff *)param;
// 	printf("player pos[0] %zu\nplayer pos[1] %zu\n",mlx->map_info.player_pos[0], mlx->map_info.player_pos[1]);
// 	if (key == 7 || key == 79)
// 	{
// 		ft_printf("pressed\n");
// 		if (mlx->map[mlx->map_info.player_pos[0]][mlx->map_info.player_pos[1] + 1] == '1')
// 		{
// 			ft_printf("Wall!\n");
// 			return ;
// 		}
// 		mlx->map[mlx->map_info.player_pos[0]][mlx->map_info.player_pos[1]] = '0';
// 		mlx->map_info.player_pos[1] += 1;
// 		mlx->step_count += 1;
// 		mlx->map[mlx->map_info.player_pos[0]][mlx->map_info.player_pos[1]] = 'P';
// 		printf("Step count: %zu\n", mlx->step_count);
// 		mlx_pixel_put_region(mlx->mlx, mlx->win,
// 		 mlx->map_info.player_pos[0] * 64,
// 		 mlx->map_info.player_pos[1] * 64, 64, 64, mlx->colours.p_colour);
// 	}
// 	printf("Next tile: %c\n",
// 	mlx->map[mlx->map_info.player_pos[0]][mlx->map_info.player_pos[1]]);
// 	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){ .rgba = 0x000000FF });
// 	draw_map(mlx->map, *mlx);
// }

void	move_right(int key, void *param)
{
	t_mlx_and_stuff *mlx = (t_mlx_and_stuff *)param;
	size_t	current_pos;

	current_pos = mlx->map_info.player_pos[1];
	printf("player pos[0] %zu\nplayer pos[1] %zu\n",mlx->map_info.player_pos[0], current_pos);
	if (key == 7 || key == 79)
	{
		ft_printf("pressed\n");
		if (mlx->map[mlx->map_info.player_pos[0]][current_pos + 1] == '1')
		{
			ft_printf("Wall!\n");
			return ;
		}
		//mlx_put_image_to_window(mlx.mlx, mlx.win, mlx->img_floor)
		mlx->map[mlx->map_info.player_pos[0]][current_pos] = '0';
	//	current_pos += 1;
		mlx->step_count += 1;
		mlx->map[mlx->map_info.player_pos[0]][current_pos + 1] = 'P';
		printf("Step count: %zu\n", mlx->step_count);
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, mlx->img_floor, current_pos * 64, mlx->map_info.player_pos[0] * 64, 4, 4, 0);
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, mlx->img_p_right, (current_pos + 1) * 64, mlx->map_info.player_pos[0] * 64, 4, 4, 0);
	//	mlx_pixel_put_region(mlx->mlx, mlx->win,
	//	 mlx->map_info.player_pos[1] * 64,
	//	 mlx->map_info.player_pos[0] * 64, 64, 64, mlx->colours.p_colour);
	}
	//draw_map(mlx->map, *mlx);
}

void	draw_l_r_walls(char **map, t_mlx_and_stuff t_mlx, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_lwall, column * 64, row * 64, 4, 4, 0);
	if (column == t_mlx.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_rwall, column * 64, row * 64, 4, 4, 0);
}

void	draw_t_l_r_walls(char **map, t_mlx_and_stuff t_mlx, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_tlwall, column * 64, row * 64, 4, 4, 0);
	if (column == t_mlx.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_trwall, column * 64, row * 64, 4, 4, 0);
}

void	draw_b_l_r_walls(char **map, t_mlx_and_stuff t_mlx, size_t row, size_t column)
{
	(void)map;
	if (column == 0)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_blwall, column * 64, row * 64, 4, 4, 0);
	if (column == t_mlx.map_info.map_width - 1)
		mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_brwall, column * 64, row * 64, 4, 4, 0);
}

void	draw_map(char **map, t_mlx_and_stuff t_mlx)
{
	size_t row = 0;
	while (row < t_mlx.map_info.map_height)
	{
		size_t column = 0;
		while (column < t_mlx.map_info.map_width)
		{
			if (row == 0 && (column == 0 || column == t_mlx.map_info.map_width - 1))
				draw_t_l_r_walls(map, t_mlx, row, column);
			if ((row > 0 && row < t_mlx.map_info.map_height) && (column == 0 || column == t_mlx.map_info.map_width - 1))
				draw_l_r_walls(map, t_mlx, row, column);
			if (row == t_mlx.map_info.map_height - 1 && (column == 0 || column == t_mlx.map_info.map_width - 1))
				draw_b_l_r_walls(map, t_mlx, row, column);
			if ((column > 0 && column < t_mlx.map_info.map_width - 1) && map[row][column] == '1')
    			mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_1wall, column * 64, row * 64, 4, 4, 0);
			if (map[row][column] == '0')
				mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_floor, column * 64, row * 64, 4, 4, 0);
			if (map[row][column] == 'C')
				mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 64,
				 row *64, 64, 64, t_mlx.colours.c_colour);
			if (map[row][column] == 'E')
				mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 64,
				 row *64, 64, 64, t_mlx.colours.e_colour);
			if (map[row][column] == 'P')
				mlx_put_transformed_image_to_window(t_mlx.mlx, t_mlx.win, t_mlx.img_p_left, column * 64, row * 64, 4, 4, 0);
			column++;
		}
		row++;
	}
}
	//	}
	// size_t row = 0;
	// while (row < t_mlx.map_info.map_height)
	// {
	// 	size_t column = 0;
	// 	while (column < t_mlx.map_info.map_width)
	// 	{
	// 		if (map[row][column] == '1')
    // 			mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 32,
	// 			 row *32, 32, 32, t_mlx.colours.wall_colour);
	// 		if (map[row][column] == 'C')
	// 			mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 32,
	// 			 row *32, 32, 32, t_mlx.colours.c_colour);
	// 		if (map[row][column] == 'E')
	// 			mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 32,
	// 			 row *32, 32, 32, t_mlx.colours.e_colour);
	// 		if (map[row][column] == 'P')
	// 			mlx_pixel_put_region(t_mlx.mlx, t_mlx.win, column * 32,
	// 			 row *32, 32, 32, t_mlx.colours.p_colour);
	// 		column++;
	// 	}
	// 	row++;
	// }
// 	}
// }

void	destroy_all_image(t_mlx_and_stuff t_mlx)
{
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_blwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_brwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_tlwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_trwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_lwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_rwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_twall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_bwall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_1wall);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_floor);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_p_down);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_p_up);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_p_right);
	mlx_destroy_image(t_mlx.mlx, t_mlx.img_p_left);
}
//transparency test
char **arraycopy(char **map)
{
	int len;
	int height;
	char **dup;

	height = 0;
	len = ft_strlen(map[0]);
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

int	gameshit(char **map, t_map_count map_info)
{
	t_mlx_and_stuff t_mlx;
	char **map1; //transparency test

	map1 = arraycopy(map);
	make0(map1);
	t_mlx.map_info = map_info;
	t_mlx.mlx = mlx_init();
	t_mlx.map = map;


	ft_bzero(&t_mlx.win_info, sizeof(mlx_window_create_info));
	t_mlx.win_info.title = "Test_window";
	t_mlx.win_info.height = 64 * map_info.map_height;
	t_mlx.win_info.width = 64 * map_info.map_width;
	t_mlx.step_count = 0;
	t_mlx.img_width = 0;
	t_mlx.img_height = 0;
	t_mlx.img_lwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/leftwall.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_rwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/rightwall.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_twall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/topwall.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_bwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/bottomwall.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_tlwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/topleft.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_trwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/topright.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_blwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/bottomleft.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_brwall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/bottomright.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_1wall = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/1wall.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_floor = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/16_16.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_p_down = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/krobusdown.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_p_up = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/krobusup.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_p_left = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/krobusleft.png", &t_mlx.img_width, &t_mlx.img_height);
	t_mlx.img_p_right = mlx_new_image_from_file(t_mlx.mlx, "textures/example/tiles/walls/krobusright.png", &t_mlx.img_width, &t_mlx.img_height);

	t_mlx.win = mlx_new_window(t_mlx.mlx, &t_mlx.win_info);

	mlx_set_fps_goal(t_mlx.mlx, 30);

	ft_bzero(&t_mlx.colours, sizeof(t_colours));

	int i = 0;
	while (i < (64 * 64))
		t_mlx.colours.p_colour[i++].rgba = 0x0000FFFF;
	i = 0;
	while (i < (64 * 64))
		t_mlx.colours.c_colour[i++].rgba = 0xf9d624FF;
	i = 0;
	while (i < (64 * 64))
		t_mlx.colours.wall_colour[i++].rgba = 0xFF0000FF;
	i = 0;
	while (i < (64 * 64))
		t_mlx.colours.e_colour[i++].rgba = 0xa76a22FF;
	i = 0;


	mlx_on_event(t_mlx.mlx, t_mlx.win, MLX_KEYDOWN, move_right, &t_mlx);
	mlx_on_event(t_mlx.mlx, t_mlx.win, MLX_KEYDOWN, exit_event, t_mlx.mlx);
	mlx_on_event(t_mlx.mlx, t_mlx.win, MLX_WINDOW_EVENT, exit_event, t_mlx.mlx);

	printmap(map1);
	draw_map(map1, t_mlx);
	draw_map(map, t_mlx);
    mlx_loop(t_mlx.mlx);

	destroy_all_image(t_mlx);
	// mlx_destroy_image(t_mlx.mlx, t_mlx.img);
    mlx_destroy_window(t_mlx.mlx, t_mlx.win);
    mlx_destroy_context(t_mlx.mlx);
	free_memory(map1);
	return (0);
}
