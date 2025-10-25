
#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s = "";
	int		fd;

	if (ac != 2)
		return 1;
	fd = open(av[1], O_RDONLY);
	printf("fd=%d\n", fd);
	s = get_next_line(fd);
	printf("%s\n", s);
	return 0;
}
