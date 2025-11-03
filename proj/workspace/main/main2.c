
#include "work.h"

int	main(int ac, char *av[])
{
	int		fd;
	char	*res;

	if (ac != 2)
		return (1);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (2);
	res = ft_read(fd);
	close(fd);
	printf("%s\n", res);
	free(res);
	return (0);
}
