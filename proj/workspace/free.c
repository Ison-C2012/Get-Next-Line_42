
#include "work.h"

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
	return 0;
}

