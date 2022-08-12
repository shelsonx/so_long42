/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:57:51 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/12 16:53:31 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_ext_valid(char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (filename[size -1] != 'r' || filename[size -2] != 'e'
		|| filename[size -3] != 'b' || filename[size -4] != '.')
		return (0);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	num_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

t_window	get_window_size(char **map)
{
	t_window	window;

	if (!map[0] || !num_rows(map))
	{
		window.width = 0;
		window.height = 0;
		return (window);
	}
	window.width = ft_strlen(map[0]) * SPRITE;
	window.height = num_rows(map) * SPRITE;
	return (window);
}

int	is_valid_characters(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != 'C' &&
				map[x][y] != 'E' && map[x][y] != 'P' && map[x][y] != 'B')
				return (FALSE);
			y++;
		}
		x++;
	}
	return (TRUE);
}
