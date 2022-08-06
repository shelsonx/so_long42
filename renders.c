/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:45:37 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 05:13:41 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_image *image, int x, int y)
{
	image->x = x;
	image->y = y;
}

void	render(t_game *game, t_image *image, int x, int y)
{
	image->x = y;
	image->y = x;
	draw_image(game, image);
	update_position(image, x, y);
}

int	render_map(t_game *game)
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
				render(game, &game->coin_0, x, y);
			if (game->map[x][y] == 'E')
				render(game, &game->exit, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
