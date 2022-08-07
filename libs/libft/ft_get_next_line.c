/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:05:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/08/07 16:11:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_new_line(char *line, int line_size);
int		get_line_size(char	*line);
char	*join_read(int fd, char *line);
char	*finally(char *first_str, char *second_str);

char	*ft_get_next_line(int fd)
{
	char		*line;
	char		*new_line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!next_line)
		line = ft_strdup("");
	else
		line = ft_strdup(next_line);
	line = join_read(fd, line);
	if (line == NULL)
		return (finally(line, next_line));
	new_line = create_new_line(line, get_line_size(line));
	free(next_line);
	next_line = ft_strchr(line, '\n');
	if (next_line)
		next_line = ft_strdup(next_line + 1);
	free(line);
	return (new_line);
}

char	*finally(char *first_str, char *second_str)
{
	free(first_str);
	free(second_str);
	return (NULL);
}

char	*join_read(int fd, char *line)
{
	char		*buffer;
	char		*temp;
	int			size_read;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size_read = BUFFER_SIZE;
	while (!ft_strchr(line, '\n') && size_read == BUFFER_SIZE)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if ((size_read < 0) || (size_read == 0 && line[0] == '\0'))
			return (finally(buffer, line));
		buffer[size_read] = '\0';
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

int	get_line_size(char	*line)
{
	int	size;

	size = 0;
	while (line[size] && line[size] != '\n')
		size++;
	if (line[size] == '\n')
		return (size + 1);
	return (size);
}

char	*create_new_line(char *line, int line_size)
{
	char	*new_line;

	new_line = (char *) malloc(sizeof(char) * line_size + 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, line, line_size + 1);
	return (new_line);
}
