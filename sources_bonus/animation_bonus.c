/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:33:53 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/09 02:59:32 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	swap_bomb(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.bomb.addr);
	game->image_bonus.bomb.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->image_bonus.bomb.width, &game->image_bonus.bomb.height);
}

void	swap_play_for_bomb(t_game *game, char coord, int move)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = game->image_bonus.bomb.x;
	old_pos_y = game->image_bonus.bomb.y;
	if (coord == 'x')
	{
		if (move == INCREMENT)
			game->image_bonus.bomb.x += 1;
		else if (move == DECREMENT)
			game->image_bonus.bomb.x -= 1;
	}
	else if (coord == 'y')
	{
		if (move == INCREMENT)
			game->image_bonus.bomb.y += 1;
		else if (move == DECREMENT)
			game->image_bonus.bomb.y -= 1;
	}
	game->map[old_pos_x][old_pos_y] = '0';
	game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y] = 'B';
}

int	animation(t_game *game)
{
	swap_bomb(game, PATH_IMG_BOMB_1);
	render_map(game);
	swap_bomb(game, PATH_IMG_BOMB);
	render_map(game);
	return (0);
}
