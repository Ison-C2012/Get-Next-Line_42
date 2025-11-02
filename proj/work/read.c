
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char *av[])
{
	char	buf[BUFSIZE];
	int		fd;
	int		rc;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (2);

	rc = 1;
	while (rc)
	{
		rc = read(fd, buf, sizeof(char) * 100);
		printf("%s\n", buf);
		memset(buf, 0, BUFSIZE);
	}
	close(fd);
	return (0);
}
