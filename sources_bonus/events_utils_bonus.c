/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:25:13 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/07 20:00:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_play_for_space(t_game *game, char coord, int move)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = game->tux.x;
	old_pos_y = game->tux.y;
	if (coord == 'x')
	{
		if (move == INCREMENT)
			game->tux.x += 1;
		else if (move == DECREMENT)
			game->tux.x -= 1;
	}
	else if (coord == 'y')
	{
		if (move == INCREMENT)
			game->tux.y += 1;
		else if (move == DECREMENT)
			game->tux.y -= 1;
	}
	game->map[old_pos_x][old_pos_y] = '0';
	game->map[game->tux.x][game->tux.y] = 'P';
}

void	finalize_player(t_game *game)
{
	game->map[game->tux.x][game->tux.y] = '0';
}
