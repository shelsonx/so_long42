/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:40:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 22:11:39 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;
	game.map = generate_map(argv[argc - 1]);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	init_window(&game);
	load_images(&game);
	render_map(&game);
	game.wall.x = 0;
	game.wall.y = 0;
	game.space.x = 0;
	game.space.y = 0;
	game.tux_right.x = 0;
	game.tux_right.y = 0;
	game.coin_0.x = 0;
	game.coin_0.y = 0;
	//mlx_put_image_to_window(game.mlx_ptr, game.window.win_ptr, game.wall.addr, 0, 0);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.window.win_ptr);
	free(game.mlx_ptr);
	free_tab(game.map);
	return (0);
}