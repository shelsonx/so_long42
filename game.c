/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 04:50:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 05:09:50 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	free_tab(game->map);
	mlx_destroy_image(game->mlx_ptr, game->tux.addr);
	mlx_destroy_image(game->mlx_ptr, game->coin_0.addr);
	mlx_destroy_image(game->mlx_ptr, game->exit.addr);
	mlx_destroy_image(game->mlx_ptr, game->space.addr);
	mlx_destroy_image(game->mlx_ptr, game->wall.addr);
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
