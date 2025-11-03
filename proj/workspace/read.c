
#include "work.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 42

char	*ft_read(int fd)
{
	char	*content = "";
	char	*buf;
	char	*tmp;
	int		rc;

	buf = calloc(BUFSIZE + 1, sizeof(char));
	rc = 1;
	while (rc)
	{
		rc = read(fd, buf, BUFSIZE);
		if (rc == -1)
			return (NULL);
		tmp = content;
		content = ft_strjoin(tmp, buf);
		if (tmp[0])
			free(tmp);
		memset(buf, 0, BUFSIZE);
	}
	free(buf);
	return (content);
}

