
#include "work.h"

int	main(void)
{
	char	*buf=strdup("I am Keito.\nWhat's your name?\n");
	char	*stk=strdup("Nice to Meet you. ");
	char	*line_to_cat;
	char	*line_to_res;
	char	*nlptr;
	size_t	bsize;

	bsize = strlen("I am Keito.\nWhat's your name?\n");
	nlptr = memchr(buf, '\n', bsize);
	line_to_cat = ft_substr(buf, 0, nlptr - buf + 1);
	line_to_res = ft_strjoin(stk, line_to_cat);
	free(line_to_cat);
	free(stk);
	stk = ft_substr(nlptr, 1, bsize);
	printf("%s", line_to_res);
	printf("%s", stk);
	free(line_to_res);
	free(stk);
	free(buf);
	return (0);
}

