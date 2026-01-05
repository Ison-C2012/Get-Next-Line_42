
#include "ft.h"

char	*ft_read(int fd)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE] = '\0';
	return (buf);
}
