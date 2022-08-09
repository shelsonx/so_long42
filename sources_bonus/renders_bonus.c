/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:45:37 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/08 20:51:26 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *game, t_image *image, int x, int y)
{
	image->x = x;
	image->y = y;
	draw_image(game, image);
}

void	render_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		game->image_bonus.back_move.addr, game->window.width / 2 - 32, 10);
	mlx_string_put(game->mlx_ptr, game->window.win_ptr,
		game->window.width / 2 + 5, 22, 0xFFFFFF, moves);
	free(moves);
}

void	render_enemy(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'B')
				render(game, &game->image_bonus.bomb, x, y);
			y++;
		}
		x++;
	}
}

void	render_default_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				render(game, &game->wall, x, y);
			if (game->map[x][y] == 'P')
				render(game, &game->tux, x, y);
			if (game->map[x][y] == '0')
				render(game, &game->space, x, y);
			if (game->map[x][y] == 'C')
				render(game, &game->coin, x, y);
			if (game->map[x][y] == 'E')
				render(game, &game->door, x, y);
			y++;
		}
		x++;
	}
}

int	render_map(t_game *game)
{
	render_default_map(game);
	render_moves(game);
	render_enemy(game);
	return (0);
}
