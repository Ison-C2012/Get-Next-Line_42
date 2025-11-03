
#include "work.h"

char	*ft_concatenate(char *s)
{
	static char *stk = "";
	char		*tmp;

	tmp = stk;
	stk = ft_strjoin(tmp, s);
//	if (tmp[0])
	if (*tmp)
		free(tmp);
	if (stk)
		return (stk);
	return (NULL);
}

