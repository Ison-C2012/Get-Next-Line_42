/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/05 01:56:56 by keitotak         ###   ########.fr       */
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
		nl->len_to = 0;
		nl->len_from = 0;
		return (nl);
	}
	nl->ptr = ft_strchr(s, '\n');
	nl->len_to = nl->ptr - s + 1;
	nl->len_from = ft_strlen(s) - nl->len_to;
	return (nl);
}

char	*ft_read(int fd)
{
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE] = '\0';
	return (buf);
}

char	*ft_save_add(char *save, char *add)
{
	char	*ptr;

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

char	*get_next_line(int fd)
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
	line = ft_substr(save, 0, nl->len_to);
	save = ft_save_trans(save, nl);
	free(nl);
	return (line);
}
