/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:32:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 05:13:08 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img_pos_tux(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->tux.addr);
	game->tux.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->tux.width, &game->tux.height);
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
	game->coin_0.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_COIN_0,
			&game->coin_0.width, &game->coin_0.height);
	game->exit.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_EXIT,
			&game->exit.width, &game->exit.height);
}

void	draw_image(t_game *game, t_image *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->addr, img->x * SPRITE, img->y * SPRITE);
}
