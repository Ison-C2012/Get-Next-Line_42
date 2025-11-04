
#include "work.h"

int	main(void)
{
	char *s;

	s = strdup("42 tokyo.");
	if (s)
		free(s);
	s = strdup("42 paris.");
	if (s)
		printf("%s\n", s);
	free(s);
	return 0;
}

