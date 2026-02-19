/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:03:49 by dlanehar          #+#    #+#             */
/*   Updated: 2026/02/17 15:34:16 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft.h"
# include "./get_next_line_bonus.h"
# include <stdlib.h>
# include <fcntl.h>

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

// ---- GEN UTILS
void	free_memory(char **memory);

// ---- MAP CREATION FUNCTIONS
char	**map_maker(char *map_path, t_map_count *map_info);
char	**map_loading(char *map_path);
void	map_path_check(char *mappath);
char	*load_map_to_string(char *map_path);
char	*make_string_from_file(char *buf, int fd);
char	**load_map_to_array(char *mapstr);

// ---- MAP VALIDATION
void	empty_line_check(char *res);
void	input_validity(char **map, t_map_count *map_info, t_map_errors *error);
// void	empty_line_check(char **map, t_map_errors *error);
void	dimension_check(char **map, t_map_count *map_info, t_map_errors *error);
size_t	map_height(char **map);
void	wall_check(char **map, t_map_count *map_info, t_map_errors *error);
void	check_top_bottom_walls(char **map, t_map_count *map_info, t_map_errors *error);
void	check_left_right_walls(char **map, t_map_count *map_info, t_map_errors *error);
size_t	map_height(char **map);
void	parameter_check(char **map, t_map_count *map_info, t_map_errors *error);
void	check_valid_char(char map_tile, t_map_errors *error);
void	count_player(t_map_count *count, char map_tile);
void	count_collectible(t_map_count *count, char map_tile);
void	count_exit(t_map_count *count, char map_tile);
void	validate_count(t_map_count *count, t_map_errors *error);
void	validity_check(char **map, t_map_count *map_info);
void	error_check(char **map, t_map_errors *error);
void	dimension_error(t_map_errors *error);
//void	validation_error(char *str);

void	printmap(char **map);
#endif
