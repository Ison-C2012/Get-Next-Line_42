/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/05 16:53:51 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		nl->len = 0;
		return (nl);
	}
	nl->ptr = ft_strchr(s, '\n');
	nl->len = nl->ptr - s + 1;
	return (nl);
}

char	*ft_read(int fd)
{
	char	*buf;
	int		rc;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	rc = read(fd, buf, BUFFER_SIZE);
	if (rc == -1)
	{
		free(buf);
		return (NULL);
	}
	if (rc == EOF)
	{

	}
	buf[rc] = '\0';
	return (buf);
}

char	*ft_save_add(char *save, char *add)
{
	char	*ptr;

	if (save == NULL)
	{
		save = (char *)malloc(1 * sizeof(char));
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	ptr = save;
	save = ft_strjoin(ptr, add);
	if (save == NULL)
		return (NULL);
	free(ptr);
	free(add);
	return (save);
}

char	*ft_save_trans(char *save, char *start)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (start[len])
		len++;
	ptr = save;
	if (len == 0)
		save = NULL;
	else
	{
		save = ft_substr(start, 0, len);
		if (save == NULL)
			return (NULL);
	}
	free(ptr);
	return (save);
}

char	*ft_read_to_save(char *save)
{
	while (ft_strchr(save, '\n') == NULL)
	{
		
	}
}


char	*get_next_line(int fd)
{
	static char	*save = NULL;
	t_nl		*nl;
	char		*buf;
	char		*line;

	nl = ft_get_nl(save, (t_nl *) NULL);
	while (nl->ptr == NULL)
	{
		buf = ft_read(fd);
		if (buf == NULL)
			return (ft_free(NULL, nl));
		if (*buf == '\0')
		{
			line = save;
			save = NULL;
			return (ft_free(ft_free(line, buf), nl));
		}
		save = ft_save_add(save, buf);
		if (save == NULL)
			return (ft_free(NULL, nl));
		nl = ft_get_nl(save, nl);
	}
	line = ft_substr(save, 0, nl->len);
	save = ft_save_trans(save, nl->ptr + 1);
	return (ft_free(line, nl));
}
