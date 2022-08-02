/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:32:55 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 22:12:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->wall.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_WALL, &game->wall.width, &game->wall.height);
	game->space.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_SPACE, &game->space.width, &game->space.height);
	game->tux_right.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_TUX_RIGHT, &game->tux_right.width, &game->tux_right.height);
	game->coin_0.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_COIN_0, &game->coin_0.width, &game->coin_0.height);
}

void	draw_image(t_game *game, t_image *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->addr, img->x * SPRITE, img->y * SPRITE);
}
