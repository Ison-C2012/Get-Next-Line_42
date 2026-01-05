
#include "ft.h"

char	*ft_save_add(char *save, char *add)
{
	char	*ptr;

	if (add == NULL)
		return (NULL);
	ptr = save;
	if (save == NULL)
		save = ft_strjoin("", add);
	else
		save = ft_strjoin(ptr, add);
	if (save == NULL)
		return (NULL);
	free(ptr);
	free(add);
	return (save);
}
