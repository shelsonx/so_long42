/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:33:53 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/09 16:25:50 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_fly(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.fly.addr);
	game->image_bonus.fly.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->image_bonus.fly.width, &game->image_bonus.fly.height);
}

static void	update_frame(t_game *game)
{
	if (game->frame < 7)
		game->frame++;
	else
		game->frame = 1;
}

static int	swap_flies(t_game *game, int frame)
{
	if (game->frame == 1)
		swap_fly(game, PATH_IMG_FLY_1);
	else if (game->frame == 2)
		swap_fly(game, PATH_IMG_FLY_2);
	else if (game->frame == 3)
		swap_fly(game, PATH_IMG_FLY_3);
	else if (game->frame == 4)
		swap_fly(game, PATH_IMG_FLY_4);
	else if (game->frame == 5)
		swap_fly(game, PATH_IMG_FLY_5);
	else if (game->frame == 6)
		swap_fly(game, PATH_IMG_FLY_6);
	return (frame);
}


int	animation(t_game *game)
{
	if (game->count_animations < SPEED_ANIMATION)
	{
		game->count_animations++;
		return (0);
	}
	game->count_animations = 0;
	update_frame(game);
	swap_flies(game, game->frame);
	render_map(game);
	return (0);
}
