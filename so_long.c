/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:40:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/05 05:56:59 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
		game->window.win_ptr = NULL;
		exit(0);
	}
	else if(key == KEY_DOWN || key == KEY_S)
		down(game);
	else if(key == KEY_UP || key == KEY_W)
		up(game);
	else if(key == KEY_RIGHT || key == KEY_D)
		right(game);
	else if(key == KEY_LEFT || key == KEY_A)
		left(game);
	render_map(game);
	return (0);
}

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
	mlx_hook(game.window.win_ptr, 2, 1L<<0, &close_win, &game);
	mlx_expose_hook(game.window.win_ptr, &render_map, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.window.win_ptr);
	free(game.mlx_ptr);
	free_tab(game.map);
	return (0);
}