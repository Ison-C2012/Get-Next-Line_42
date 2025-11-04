
#include "work.h"

int	is_include_nl(const char *s)
{
	while (*s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char	*get_first_line(char *s)
{
	char	*line;
	size_t	size;

	size = 0;
	while (s[size])
	{
		if (s[size++] == '\n')
			break ;
	}
	line = malloc(size + 1);
	if (line == NULL)
		return (NULL);
	strlcpy(line, s, size + 1);
	return (line);
}

char	*ft_read(int fd)
{
	static char	*stk="";
	char		*first_line;
	char		*buf;
	int			rc;

	if (is_include_nl(stk))
	{
		first_line = get_first_line(stk);

	}
	buf = calloc(BUFFER_SIZE + 1, sizeof(char));
	rc = 1;
	while (rc)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
			return (NULL);
		if (is_include_nl(buf))
		{
			first_line = ft_strjoin(stk, get_first_line(buf));
			if (stk[0] != '\0')
				free(stk);
			return (first_line);
		}
		else
		{
			stk = ft_strjoin(stk, buf);
			memset(buf, 0, BUFFER_SIZE);
		}
	}
	free(buf);
	first_line = strdup(stk);
	free(stk);
	return (stk);
}

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

