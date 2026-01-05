
#include "ft.h"

#include <fcntl.h>
#include <unistd.h>
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
	while (s)
	{
		s = ft_process(fd);
		if (s)
		{
			printf("%s", s);
			free(s);
		}
	}
	close(fd);
	return 0;
}
