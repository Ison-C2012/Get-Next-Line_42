
#include "ft.h"

char	*ft_process(int fd)
{
	static char	*save = NULL;
	t_nl		*nl;
	char		*buf;
	char		*line;

	nl = NULL;
	nl = ft_get_nl(save, nl);
	while (nl->ptr == NULL)
	{
		buf = ft_read(fd);
		if (buf == NULL)
			return (ft_free_nl(nl));
		save = ft_save_add(save, buf);
		if (save == NULL)
			return (ft_free_nl(nl));
		nl = ft_get_nl(save, nl);
	}
	line = ft_get_line(save, nl->len_to);
	save = ft_save_trans(save, nl);
	free(nl);
	return (line);
}
