/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:33:53 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/10 17:19:42 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_game *game)
{
	if (game->count_animations < SPEED_ANIMATION)
	{
		game->count_animations++;
		return (0);
	}
	game->count_animations = 0;
	update_frame(game);
	swap_flies(game, game->frame);
	swap_coins(game, game->frame);
	render_map(game);
	return (0);
}
