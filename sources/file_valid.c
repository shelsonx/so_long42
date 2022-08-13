

#include "so_long.h"

char	*get_lines_map(char *path)
{
	char	*line;
	char	*tmp;
	char	*lines;
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
	close(fd);
	return (lines);
}

int	is_empty_line(char *lines)
{
	if (lines[0] == '\n')
		return (TRUE);
	while (*lines)
	{
		if (*lines == '\n' && *(lines + 1) == '\n')
			return (TRUE);
		lines++;
	}
	return (FALSE);
} 

int	valid_file(char *path)
{
    char	*lines;

	lines = get_lines_map(path);
	if (is_empty_line(lines))
	{
		free(lines);
		return (FALSE);
	}
	free(lines);
	return (TRUE);
}
