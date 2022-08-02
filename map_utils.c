/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:57:51 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/02 15:47:26 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
