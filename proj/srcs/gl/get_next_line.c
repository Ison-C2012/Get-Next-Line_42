/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:01:07 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/06 15:08:55 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	does_include_nl(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (0);
}

char	*read_to_buf(char *buf, int fd)
{
	int	rc;

	if (buf == NULL)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return (NULL);
	}
	rc = read(fd, buf, BUFFER_SIZE);
	if (rc == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[rc] = '\0';
	return (buf);
}

char	*add_to_save(char *save, char *add)
{
	char	*ptr;

	if (save == NULL)
	{
		save = malloc(1 * sizeof(char));
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	ptr = save;
	save = ft_strjoin(ptr, add);
	return (ret_cpy_free(&save, &ptr));
}

char	*trans_save(char *save, char *start)
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
		save = ft_substr(start, 0, len);
	return (ret_cpy_free(&save, &ptr));
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*buf;
	size_t		len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = NULL;
	while (does_include_nl(save) == 0)
	{
		buf = read_to_buf(buf, fd);
		if (buf == NULL)
			return (ret_cpy_free(&buf, &save));
		else if (buf[0] == '\0')
			return (ret_cpy_free(&save, &buf));
		save = add_to_save(save, buf);
		if (save == NULL)
			return (ret_cpy_free(&save, &buf));
	}
	len = does_include_nl(save);
	line = ft_substr(save, 0, len);
	save = trans_save(save, save + len);
	return (ret_cpy_free(&line, &buf));
}

//		if (rc < BUFFER_SIZE)
//			return (ret_cpy(save));
