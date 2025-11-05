
#include "work.h"

void	ft_free(char *s)
{
	free(s);
}

int	main(void)
{
	char *s;
	char *tmp;

	s = strdup("42 tokyo.");
	tmp = s;
	s = strdup("42 paris.");
	printf("%s\n", tmp);
	printf("%s\n", s);
	free(tmp);
	free(s);

	s = strdup("why non-freeable?");
	ft_free(s);
	return 0;
}

