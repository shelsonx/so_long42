/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:52:41 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/12 13:03:32 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_position(char *current, char *next, char old, char new)
{
	*current = new;
	*next = old;
}

void	swap_enemy_for_space(t_game *game, int direction, int x, int y)
{
	if (direction == INCREMENT)
	{
		if (game->map[x][y] == 'B' && game->map[x + 1][y] == '0')
			swap_position(&game->map[x][y], &game->map[x + 1][y], 'B', '0');
		else if (game->map[x][y] == 'B' && game->map[x + 1][y] == 'P')
			game_over(game);
	}
	else if (direction == DECREMENT)
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

/* void	load_img_pos_enemy(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.fly.addr);
	game->image_bonus.fly.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->image_bonus.fly.width, &game->image_bonus.fly.height);
}

void	enemy_left(t_game *game)
{
	if (game->map[game->image_bonus.fly.x][game->image_bonus.fly.y - 1] == 'P')
		game_over(game);
	else if (game->map[game->image_bonus.fly.x][game->image_bonus.fly.y - 1] == '0')
	{
		//load_img_pos_enemy(game, PATH_IMG_FLY);
		swap_enemies(game, 'y', DECREMENT);
	}
}

void	enemy_right(t_game *game)
{
	if (game->map[game->image_bonus.fly.x][game->image_bonus.fly.y + 1] == 'P')
		game_over(game);
	else if (game->map[game->image_bonus.fly.x][game->image_bonus.fly.y + 1] == '0')
	{
		//load_img_pos_enemy(game, PATH_IMG_FLY);
		swap_enemies(game, 'y', INCREMENT);
	}
}
 */