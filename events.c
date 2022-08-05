/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:37:29 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/05 05:36:05 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	events(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_win(game);
	else if (key == KEY_DOWN || key == KEY_S)
		down(game);
	else if (key == KEY_UP || key == KEY_W)
		up(game);
	else if (key == KEY_RIGHT || key == KEY_D)
		right(game);
	else if (key == KEY_LEFT || key == KEY_A)
		left(game);
	render_map(game);
	return (0);
}
