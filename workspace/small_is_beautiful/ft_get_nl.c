
#include "ft.h"

t_nl	*ft_get_nl(char *s, t_nl *nl)
{
	if (nl == NULL)
	{
		nl = (t_nl *)malloc(1 * sizeof(t_nl));
		if (nl == NULL)
			return (NULL);
	}
	if (s == NULL)
	{
		nl->ptr = NULL;
		nl->len_to = 0;
		nl->len_from = 0;
		return (nl);
	}
	nl->ptr = ft_strchr(s, '\n');
	if (nl->ptr == NULL)
	{
		nl->len_to = 0;
		nl->len_from = 0;
		return (nl);
	}
	nl->len_to = nl->ptr - s + 1;
	nl->len_from = ft_strlen(s) - nl->len_to;
	return (nl);
}
