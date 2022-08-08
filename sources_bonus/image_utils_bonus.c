/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:32:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/08 12:58:41 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_img_pos_tux(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->tux.addr);
	game->tux.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->tux.width, &game->tux.height);
}

void	load_images_bonus(t_game *game)
{
	game->image_bonus.back_move.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_BACK_MOVE,
			&game->image_bonus.back_move.width,
			&game->image_bonus.back_move.height);
	game->image_bonus.bomb.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_BOMB,
			&game->image_bonus.bomb.width, &game->image_bonus.bomb.height);
	game->image_bonus.game_over.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_GAME_OVER,
			&game->image_bonus.game_over.width,
			&game->image_bonus.game_over.height);
}

void	load_images(t_game *game)
{
	game->wall.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_WALL,
			&game->wall.width, &game->wall.height);
	game->space.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_SPACE, &game->space.width,
			&game->space.height);
	game->tux.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_TUX_RIGHT,
			&game->tux.width, &game->tux.height);
	game->coin.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_COIN_0,
			&game->coin.width, &game->coin.height);
	game->door.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_EXIT,
			&game->door.width, &game->door.height);
	load_images_bonus(game);
}

void	draw_image(t_game *game, t_image *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->addr, img->y * SPRITE, img->x * SPRITE);
}
