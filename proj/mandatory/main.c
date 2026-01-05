#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s = "";
	int		fd;
	int		cnt;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (2);
	cnt = 0;
	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		cnt++;
	}
	close(fd);
	return 0;
}
