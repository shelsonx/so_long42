/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:52:41 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/12 15:15:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_enemy_for_space(t_game *game, int direction, int x, int y)
{
	if (direction == DOWN_ENEMY)
	{
		if (game->map[x][y] == 'B' && game->map[x + 1][y] == '0')
			swap_position(&game->map[x][y], &game->map[x + 1][y], 'B', '0');
		else if (game->map[x][y] == 'B' && game->map[x + 1][y] == 'P')
			game_over(game);
	}
	else if (direction == UP_ENEMY)
	{
		if (game->map[x][y] == 'B' && game->map[x - 1][y] == '0')
			swap_position(&game->map[x][y], &game->map[x - 1][y], 'B', '0');
		else if (game->map[x][y] == 'B' && game->map[x - 1][y] == 'P')
			game_over(game);
	}
}

void	swap_enemies(t_game *game, int direction)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'B')
				swap_enemy_for_space(game, direction, x, y);
			y++;
		}
		x++;
	}
}

void	swap_direction(t_game *game)
{
	if (game->movement == 1)
		swap_enemies(game, UP_ENEMY);
	else if (game->movement == 2)
		swap_enemies(game, UP_ENEMY);
	else if (game->movement == 3)
		swap_enemies(game, UP_ENEMY);
	else if (game->movement == 4)
		swap_enemies(game, DOWN_ENEMY);
	else if (game->movement == 5)
		swap_enemies(game, DOWN_ENEMY);
}

void	update_movement(t_game *game)
{
	if (game->movement < 6)
		game->movement++;
	else
		game->movement = 1;
}

void	moves(t_game *game)
{
	if (game->moves_enemies < SPEED_MOVE_ENEMY)
	{
		game->moves_enemies++;
		return ;
	}
	game->moves_enemies = 0;
	update_movement(game);
	swap_direction(game);
	render_map(game);
}
