/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:04 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/07 16:09:34 by sjhony-x         ###   ########.fr       */
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
	line = ft_get_next_line(fd);
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = ft_get_next_line(fd);
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

int	is_valid_wall(char **map)
{
	int		i;
	char	*first_line;
	char	*last_line;

	first_line = map[0];
	last_line = map[num_rows(map)-1];
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (first_line[i] && last_line[i])
	{
		if (first_line[i] != '1' || last_line[1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	get_qtd_character(char **map, char character)
{
	int	row;
	int	colum;
	int	len_rows;
	int	len_colums;
	int	count_char;

	count_char = 0;
	row = 1;
	len_rows = num_rows(map);
	len_colums = ft_strlen(map[0]);
	while (row < len_rows - 1)
	{
		colum = 1;
		while (colum < len_colums - 1)
		{
			if (map[row][colum] == character)
				count_char++;
			colum++;
		}
		row++;
	}
	return (count_char);
}

int	is_valid_map(char **map)
{
	if (is_equal_colum_size(map) == 0 || is_valid_wall(map) == 0)
		return (FALSE);
	if (get_qtd_character(map, 'P') != 1)
		return (FALSE);
	if (get_qtd_character(map, 'E') < 1 || get_qtd_character(map, 'C') < 1)
		return (FALSE);
	return (TRUE);
}
