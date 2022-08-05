/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:36:49 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/05 22:06:35 by sjhony-x         ###   ########.fr       */
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
	if (game->map[game->tux_right.x + 1][game->tux_right.y] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		close_win(game);
	}
	else if (game->map[game->tux_right.x + 1][game->tux_right.y] != '1' &&
			game->map[game->tux_right.x + 1][game->tux_right.y] != 'E')
	{
		if (game->map[game->tux_right.x + 1][game->tux_right.y] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_DOWN);
		swap_play_for_space(game, 'x', INCREMENT);
		game->moves++;
	}
}

void	up(t_game *game)
{
	if (game->map[game->tux_right.x - 1][game->tux_right.y] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		close_win(game);
	}
	else if (game->map[game->tux_right.x - 1][game->tux_right.y] != '1' &&
			game->map[game->tux_right.x - 1][game->tux_right.y] != 'E')
	{
		if (game->map[game->tux_right.x - 1][game->tux_right.y] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_UP);
		swap_play_for_space(game, 'x', DECREMENT);
		game->moves++;
	}
}

void	right(t_game *game)
{
	if (game->map[game->tux_right.x][game->tux_right.y + 1] == 'E' &&
			game->collectibles == 0)
	{
		game->moves++;
		finalize_player(game);
		close_win(game);
	}
	else if (game->map[game->tux_right.x][game->tux_right.y + 1] != '1' &&
			game->map[game->tux_right.x][game->tux_right.y + 1] != 'E')
	{
		if (game->map[game->tux_right.x][game->tux_right.y + 1] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_RIGHT);
		swap_play_for_space(game, 'y', INCREMENT);
		game->moves++;
	}
}

void	left(t_game *game)
{
	if (game->map[game->tux_right.x][game->tux_right.y - 1] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		close_win(game);
	}
	else if (game->map[game->tux_right.x][game->tux_right.y - 1] != '1' &&
			game->map[game->tux_right.x][game->tux_right.y - 1] != 'E')
	{
		if (game->map[game->tux_right.x][game->tux_right.y - 1] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_LEFT);
		swap_play_for_space(game, 'y', DECREMENT);
		game->moves++;
	}
}
