/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:04 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/07/28 22:51:05 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**generate_map(char *path)
{
	char	*line;
	char	*tmp;
	char	*lines;
	char	**map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	map = ft_split(lines, '\n');
	free(lines);
	close(fd);
	return (map);
}

int	is_equal_colum_size(char **map)
{
	char	*first_line;
	int		i;

	first_line = map[0];
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(first_line))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	num_rows(char **tab)
{
	int	rows;

	rows = 0;
	while (tab[rows])
		rows++;
	return (rows);
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
