
#include "ft.h"

char	*ft_save_trans(char *save, t_nl *nl)
{
	char	*ptr;

	ptr = save;
	save = ft_substr(nl->ptr, 1, nl->len_from + 1);
	if (save == NULL)
		return (NULL);
	free(ptr);
	return (save);
}
