/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:16:00 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/10 21:20:13 by sjhony-x         ###   ########.fr       */
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

void	swap_coin(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->coin.addr);
	game->coin.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->coin.width, &game->coin.height);
}

void	update_frame(t_game *game)
{
	if (game->frame < 8)
		game->frame++;
	else
		game->frame = 1;
}

int	swap_coins(t_game *game, int frame)
{
	if (game->frame == 1)
		swap_coin(game, PATH_IMG_COIN_1);
	else if (game->frame == 2)
		swap_coin(game, PATH_IMG_COIN_2);
	else if (game->frame == 3)
		swap_coin(game, PATH_IMG_COIN_3);
	else if (game->frame == 4)
		swap_coin(game, PATH_IMG_COIN_4);
	else if (game->frame == 5)
		swap_coin(game, PATH_IMG_COIN_5);
	else if (game->frame == 6)
		swap_coin(game, PATH_IMG_COIN_6);
	else if (game->frame == 7)
		swap_coin(game, PATH_IMG_COIN_7);
	return (frame);
}

int	swap_flies(t_game *game, int frame)
{
	if (game->frame == 1)
		swap_fly(game, PATH_IMG_FLY);
	else if (game->frame == 2)
		swap_fly(game, PATH_IMG_FLY_1);
	else if (game->frame == 3)
		swap_fly(game, PATH_IMG_FLY);
	else if (game->frame == 4)
		swap_fly(game, PATH_IMG_FLY_1);
	else if (game->frame == 5)
		swap_fly(game, PATH_IMG_FLY);
	else if (game->frame == 6)
		swap_fly(game, PATH_IMG_FLY_1);
	else if (game->frame == 7)
		swap_fly(game, PATH_IMG_FLY);
	return (frame);
}
