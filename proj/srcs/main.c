
#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s = "";
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (2);
	for (int i=0;i<3;i++)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (3);
		printf("%s", s);
		free(s);
	}
	close(fd);
	return 0;
}
