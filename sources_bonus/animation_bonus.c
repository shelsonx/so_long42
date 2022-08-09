/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:33:53 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/09 16:25:50 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#include <time.h> //apagar depois
  
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


void	swap_bomb(t_game *game, char *path)
{
	
	mlx_destroy_image(game->mlx_ptr, game->image_bonus.bomb.addr);
	game->image_bonus.bomb.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, path,
			&game->image_bonus.bomb.width, &game->image_bonus.bomb.height);
}

void	swap_play_for_bomb(t_game *game, char coord, int move)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = game->image_bonus.bomb.x;
	old_pos_y = game->image_bonus.bomb.y;
	if (coord == 'x')
	{
		if (move == INCREMENT)
			game->image_bonus.bomb.x += 1;
		else if (move == DECREMENT)
			game->image_bonus.bomb.x -= 1;
	}
	else if (coord == 'y')
	{
		if (move == INCREMENT)
			game->image_bonus.bomb.y += 1;
		else if (move == DECREMENT)
			game->image_bonus.bomb.y -= 1;
	}
	game->map[old_pos_x][old_pos_y] = '0';
	game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y] = 'B';
}

void	left_animation(t_game *game)
{
	if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y - 1] == 'P')
		game_over(game);
	else if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y - 1] == '0')
	{
		swap_bomb(game, PATH_IMG_BOMB);
		swap_play_for_bomb(game, 'y', DECREMENT);
	}
}

void	right_animation(t_game *game)
{
	if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == 'P')
		game_over(game);
	else if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == '0')
	{
		swap_bomb(game, PATH_IMG_BOMB);
		swap_play_for_bomb(game, 'y', INCREMENT);
	}
}

int	animation(t_game *game)
{
	/* if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y - 1] == '0' || 
		game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y - 1] == 'P')
	{
		delay(10);
		left_animation(game);
		swap_bomb(game, PATH_IMG_BOMB_1);
		render_map(game);
		swap_bomb(game, PATH_IMG_BOMB);
		render_map(game);
	}
	else if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == '0' ||
			game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == 'P')
	{
		while (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == '0')
		{
			delay(10);
			right_animation(game);
			swap_bomb(game, PATH_IMG_BOMB_1);
			render_map(game);
			swap_bomb(game, PATH_IMG_BOMB);
			render_map(game);
			if (game->map[game->image_bonus.bomb.x][game->image_bonus.bomb.y + 1] == 'P')
				game_over(game);
		}
	} */
	swap_bomb(game, PATH_IMG_BOMB);
	render_map(game);
	swap_bomb(game, PATH_IMG_BOMB_1);
	render_map(game);
	return (0);
}
