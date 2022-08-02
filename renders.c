/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:45:37 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 21:44:09 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
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
			{
				game->wall.x = y;
				game->wall.y = x;
				draw_image(game, &game->wall);
			}
			if (game->map[x][y] == 'P')
			{
				game->tux_right.x = y;
				game->tux_right.y = x;
				draw_image(game, &game->tux_right);
			}
			if (game->map[x][y] == '0' || game->map[x][y] == 'E' || game->map[x][y] == 'C')
			{
				game->space.x = y;
				game->space.y = x;
				draw_image(game, &game->space);
			}
			y++;
		}
		x++;
	}
}
