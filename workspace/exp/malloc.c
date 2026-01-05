
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		size=100;
	char	*m=malloc(size);
	for (int i=0;i<100;i++)
		printf("%p\t%d\t%zu\n", &m[i], (m[i] == '\0'), strlen(&m[i]));
	return 0;
}


