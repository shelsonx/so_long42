/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:25:56 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 16:00:14 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game game)
{
	game.window = get_window_size(game.map);
	game.window.win_ptr = mlx_new_window(
			game.mlx_ptr, game.window.width, game.window.height, "So Long");
	if (game.window.win_ptr == NULL)
	{
		free(game.window.win_ptr);
		return ;
	}
}
