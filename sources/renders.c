/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:45:37 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 15:27:57 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game, t_image *image, int x, int y)
{
	image->x = x;
	image->y = y;
	draw_image(game, image);
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
