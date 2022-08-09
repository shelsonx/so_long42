/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 04:50:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/09 16:25:45 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_game(t_game *game)
{
	free_tab(game->map);
	mlx_destroy_image(game->mlx_ptr, game->tux.addr);
	mlx_destroy_image(game->mlx_ptr, game->coin.addr);
	mlx_destroy_image(game->mlx_ptr, game->door.addr);
	mlx_destroy_image(game->mlx_ptr, game->space.addr);
	mlx_destroy_image(game->mlx_ptr, game->wall.addr);
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.back_move.addr);
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.bomb.addr);
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.game_over.addr);
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	init_window(t_game *game)
{
	game->window = get_window_size(game->map);
	game->window.win_ptr = mlx_new_window(
			game->mlx_ptr, game->window.width, game->window.height, "So Long");
	if (game->window.win_ptr == NULL)
	{
		free(game->window.win_ptr);
		return ;
	}
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	init_window(game);
	load_images(game);
	game->moves = 0;
	game->end_game = 0;
	game->collectibles = get_qtd_character(game->map, 'C');
	mlx_expose_hook(game->window.win_ptr, &render_map, game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &events, game);
	mlx_hook(game->window.win_ptr, 17, 0, &exit_game, game);
	mlx_loop_hook(game->mlx_ptr, &animation, game);
	mlx_loop(game->mlx_ptr);
}

void	set_coin_to_space(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->coin.addr);
	game->coin.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->coin.width, &game->coin.height);
}

void	game_over(t_game *game)
{
	set_coin_to_space(game, PATH_IMG_SPACE);
	load_img_pos_tux(game, PATH_IMG_GAME_OVER);
	game->end_game = 1;
}
