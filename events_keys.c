/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:36:49 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/05 13:36:51 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	game->window.win_ptr = NULL;
	exit(0);
}

void	down(t_game *game)
{
	if (game->map[game->tux_right.x + 1][game->tux_right.y] != '1' &&
			game->map[game->tux_right.x + 1][game->tux_right.y] != 'E')
		swap_play_for_space(game, 'x', INCREMENT);
}

void	up(t_game *game)
{
	if (game->map[game->tux_right.x - 1][game->tux_right.y] != '1' &&
			game->map[game->tux_right.x - 1][game->tux_right.y] != 'E')
		swap_play_for_space(game, 'x', DECREMENT);
}

void	right(t_game *game)
{
	if (game->map[game->tux_right.x][game->tux_right.y + 1] != '1' &&
			game->map[game->tux_right.x][game->tux_right.y + 1] != 'E')
		swap_play_for_space(game, 'y', INCREMENT);
}

void	left(t_game *game)
{
	if (game->map[game->tux_right.x][game->tux_right.y - 1] != '1' &&
			game->map[game->tux_right.x][game->tux_right.y - 1] != 'E')
		swap_play_for_space(game, 'y', DECREMENT);
}