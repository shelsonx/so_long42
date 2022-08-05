/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:25:13 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/05 18:28:58 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_play_for_space(t_game *game, char coord, int move)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = game->tux_right.x;
	old_pos_y = game->tux_right.y;
	if (coord == 'x')
	{
		if (move == INCREMENT)
			game->tux_right.x += 1;
		else if (move == DECREMENT)
			game->tux_right.x -= 1;
	}
	else if (coord == 'y')
	{
		if (move == INCREMENT)
			game->tux_right.y += 1;
		else if (move == DECREMENT)
			game->tux_right.y -= 1;
	}
	game->map[old_pos_x][old_pos_y] = '0';
	game->map[game->tux_right.x][game->tux_right.y] = 'P';
}

void	finalize_player(t_game *game)
{
	game->map[game->tux_right.x][game->tux_right.y] = '0';
}
