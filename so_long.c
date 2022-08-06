/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:40:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 04:49:22 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;
	game.map = generate_map(argv[argc - 1]);
	if (!is_valid_map(game.map))
	{
		ft_putendl_fd("Map inválido!", 1);
		free_tab(game.map);
		return (1);
	}
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	init_window(&game);
	load_images(&game);
	//inicialize variables...
	game.moves = 0;
	game.collectibles = get_qtd_character(game.map, 'C');
	mlx_hook(game.window.win_ptr, 2, 1L<<0, &events, &game);
	mlx_hook(game.window.win_ptr, 17, 0, &exit_game, &game);
	mlx_expose_hook(game.window.win_ptr, &render_map, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}