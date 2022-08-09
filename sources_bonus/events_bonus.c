/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:37:29 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/09 02:44:32 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	down(t_game *game)
{
	if (game->map[game->tux.x + 1][game->tux.y] == 'B')
		game_over(game);
	if (game->map[game->tux.x + 1][game->tux.y] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		exit_game(game);
	}
	else if (game->map[game->tux.x + 1][game->tux.y] != '1' &&
			game->map[game->tux.x + 1][game->tux.y] != 'E' &&
			game->end_game == 0)
	{
		if (game->map[game->tux.x + 1][game->tux.y] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_DOWN);
		swap_play_for_space(game, 'x', INCREMENT);
		game->moves++;
	}
}

void	up(t_game *game)
{
	if (game->map[game->tux.x - 1][game->tux.y] == 'B')
		game_over(game);
	else if (game->map[game->tux.x - 1][game->tux.y] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		exit_game(game);
	}
	else if (game->map[game->tux.x - 1][game->tux.y] != '1' &&
			game->map[game->tux.x - 1][game->tux.y] != 'E' &&
			game->end_game == 0)
	{
		if (game->map[game->tux.x - 1][game->tux.y] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_UP);
		swap_play_for_space(game, 'x', DECREMENT);
		game->moves++;
	}
}

void	right(t_game *game)
{
	if (game->map[game->tux.x][game->tux.y + 1] == 'B')
		game_over(game);
	else if (game->map[game->tux.x][game->tux.y + 1] == 'E' &&
			game->collectibles == 0)
	{
		game->moves++;
		finalize_player(game);
		exit_game(game);
	}
	else if (game->map[game->tux.x][game->tux.y + 1] != '1' &&
			game->map[game->tux.x][game->tux.y + 1] != 'E' &&
			game->end_game == 0)
	{
		if (game->map[game->tux.x][game->tux.y + 1] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_RIGHT);
		swap_play_for_space(game, 'y', INCREMENT);
		game->moves++;
	}
}

void	left(t_game *game)
{
	if (game->map[game->tux.x][game->tux.y - 1] == 'B')
		game_over(game);
	else if (game->map[game->tux.x][game->tux.y - 1] == 'E' &&
			game->collectibles == 0)
	{
		finalize_player(game);
		exit_game(game);
	}
	else if (game->map[game->tux.x][game->tux.y - 1] != '1' &&
			game->map[game->tux.x][game->tux.y - 1] != 'E' &&
			game->end_game == 0)
	{
		if (game->map[game->tux.x][game->tux.y - 1] == 'C')
			game->collectibles--;
		load_img_pos_tux(game, PATH_IMG_TUX_LEFT);
		swap_play_for_space(game, 'y', DECREMENT);
		game->moves++;
	}
}

int	events(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_DOWN || key == KEY_S)
		down(game);
	else if (key == KEY_UP || key == KEY_W)
		up(game);
	else if (key == KEY_RIGHT || key == KEY_D)
		right(game);
	else if (key == KEY_LEFT || key == KEY_A)
		left(game);
	render_map(game);
	return (0);
}
