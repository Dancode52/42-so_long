/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:03:49 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/26 16:22:32 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define SO_LONG_H
# include "./libft.h"
# include "./get_next_line_bonus.h"
# include "./mlx.h"
# include "./mlx_extended.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_map_count
{
	size_t	player_count;
	size_t	exit_count;
	size_t	collect_count;
	size_t	map_height;
	size_t	map_width;
	size_t	player_pos[2];
	size_t	**collect_pos;
	size_t	exit_pos[2];
	char	**map;
}	t_map_count;

typedef struct s_map_errors
{
	int	is_error;
	int	dimension_error;
	int	topbot_error;
	int	leftright_error;
	int	width_error;
	int	height_error;
	int	three_by_three;
	int	player_error;
	int	exit_error;
	int	collecible_error;
	int	char_error;
	int	fill_error;
	int	emptyline;
}	t_map_errors;

typedef struct s_colours
{
	mlx_color	p_colour[64 * 64];
	mlx_color	wall_colour[64 * 64];
	mlx_color	c_colour[64 * 64];
	mlx_color	e_colour[64 * 64];
	mlx_color	open_e_colour[64 * 64];
}	t_colours;

typedef struct s_game_state
{
// ---- MLX ----
	mlx_context				mlx;

// ---- WINDOW VARS ----
	mlx_window_create_info	win_info;
	mlx_window				win;
	int						img_w;
	int						img_h;

// ---- TEXTURE VARS ----
	size_t					tile_size_px;
	mlx_image				img_lwall;
	mlx_image				img_rwall;
	mlx_image				img_twall;
	mlx_image				img_bwall;
	mlx_image				img_tlwall;
	mlx_image				img_trwall;
	mlx_image				img_blwall;
	mlx_image				img_brwall;
	mlx_image				img_1wall;
	mlx_image				img_floor;
	mlx_image				img_p_down;
	mlx_image				img_p_up;
	mlx_image				img_p_left;
	mlx_image				img_p_right;
	t_map_count				map_info;
	t_colours				colours;

// ---- PLAYER STATS ----
	size_t					step_count;
// ---- MAP ----
	char					**map;
}	t_game_state;

// typedef struct s_floodfill_stats
// {
// 	int	collectible_hit
// }

// ---- FLOOD FILL
void	get_filling(char **map, size_t row, size_t col, t_map_count *map_info);
char	**map_copy(char **map, t_map_count *map_info);
void	set_start_point(size_t *row, size_t *column, t_map_count *map_info);
void	is_map_playable(char **copy, t_map_errors *error);
void	flood_fill(char **map, t_map_count *map_info, t_map_errors *error);

// ---- GEN UTILS
void	free_memory(char **memory);
void	free_map_info(t_map_count *map_info);
void	malloc_fail(char **map);

// ---- MAP CREATION FUNCTIONS
char	**map_maker(char *map_path, t_map_count *map_info);
char	**map_loading(char *map_path);
void	map_path_check(char *mappath);
char	*load_map_to_string(char *map_path);
char	*make_string_from_file(char *buf, int fd);
char	**load_map_to_array(char *mapstr);

// ---- INFO STORING FOR VALIDATION
void	store_player(t_map_count *map_info, size_t row, size_t column);
void	store_exit(t_map_count *map_info, size_t row, size_t column);
void	store_collect(t_map_count *m_info, size_t row, size_t col, char **map);
void	store_info(char **map, t_map_count *m_info);

// ---- MAP VALIDATION
void	empty_line_check(char *res);
void	input_validity(char **map, t_map_count *map_info, t_map_errors *error);
// void	empty_line_check(char **map, t_map_errors *error);
void	dimension_check(char **map, t_map_count *map_info, t_map_errors *error);
size_t	map_height(char **map);
void	wall_check(char **map, t_map_count *map_info, t_map_errors *error);
void	check_top_bot(char **map, t_map_count *map_info, t_map_errors *error);
void	check_left_rht(char **map, t_map_count *map_info, t_map_errors *error);
size_t	map_height(char **map);
void	parameter_check(char **map, t_map_count *map_info, t_map_errors *error);
void	check_valid_char(char map_tile, t_map_errors *error);
void	count_player(t_map_count *count, char map_tile);
void	count_collectible(t_map_count *count, char map_tile);
void	count_exit(t_map_count *count, char map_tile);
void	validate_count(t_map_count *count, t_map_errors *error);
void	validity_check(char **map, t_map_count *map_info);
//void	error_check(char **map, t_map_errors *error);
void	error_check(char **map, t_map_errors *error, t_map_count *map_info);
void	dimension_error(t_map_errors *error);
//void	validation_error(char *str);

// ---- OPEN GAME STUFF
int		run_game(char **map, t_map_count map_info);

// ---- MLX INIT FUNCS
void	game_init(t_game_state *game, char **map, t_map_count m_inf);
void	game_image_player_init(t_game_state *game);
void	game_image_ground_init(t_game_state *game);
void	game_win_init(t_game_state *game);
void	game_base_init(t_game_state *game, char **map, t_map_count m_inf);

void	printmap(char **map);
#endif
