/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:40:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/06 15:01:04 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!is_ext_valid(argv[1]))
			ft_printf("File Extension Invalid!\n");
		else
		{
			game.map = generate_map(argv[1]);
			if (!is_valid_map(game.map))
			{
				ft_printf("Map inválido!\n");
				free_tab(game.map);
				return (1);
			}
			init_game(&game);
		}
	}
	else
		ft_printf("Argument invalid!\n");
	return (0);
}
