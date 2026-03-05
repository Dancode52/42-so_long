/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:10:48 by dlanehar          #+#    #+#             */
/*   Updated: 2026/03/05 13:48:44 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

t_move	*init_moves(void)
{
	static t_move	moves[8];

	moves[0] = (t_move){W_KEY, P_UP, -1, 0};
	moves[1] = (t_move){UP_KEY, P_UP, -1, 0};
	moves[2] = (t_move){A_KEY, P_LEFT, 0, -1};
	moves[3] = (t_move){LEFT_KEY, P_LEFT, 0, -1};
	moves[4] = (t_move){S_KEY, P_DOWN, 1, 0};
	moves[5] = (t_move){DOWN_KEY, P_DOWN, 1, 0};
	moves[6] = (t_move){D_KEY, P_RIGHT, 0, 1};
	moves[7] = (t_move){RIGHT_KEY, P_RIGHT, 0, 1};
	return (moves);
}

#include <stdio.h>

int	is_free_space(t_game_state *game, t_move *mvs, size_t row, size_t col)
{
	if (game->map[row + mvs->delta_row][col + mvs->delta_col] == '1')
		return (0);
	return (1);
}

void	move_player(int in_key, void *param)
{
	t_game_state	*game;
	t_move			*moves;
	int				i;

	game = (t_game_state *)param;
	moves = init_moves();
	i = 0;
	while (i < 8)
	{
		if ((int)moves[i].key == in_key)
		{
			if (is_free_space(game, &(moves)[i],
				game->map_info.player_pos[0], game->map_info.player_pos[1]))
			{
				game->map_info.player_pos[0] += moves[i].delta_row;
				game->map_info.player_pos[1] += moves[i].delta_col;
				game->step_count++;
			}
			game->player_dir = moves[i].direction;
			break ;
		}
		i++;
	}
	draw_map(game);
	return ;
}
