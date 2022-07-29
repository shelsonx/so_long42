#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libs/libft/libft.h"

int main(void)
{
	char *lines;
	char **map;
	
	int fd = open("maps/big.ber", O_RDONLY);
	char *line = "";
	lines = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		lines = ft_strjoin(lines, line);
		free(line);
	}
	map = ft_split(lines, '\n');
	int count = 0;
	while (map[count])
		count++;
	printf("%d\n", count);
	printf("%s\n", map[6]);
	close(fd);
	return (0);
}