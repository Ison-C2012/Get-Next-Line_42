/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:01:07 by keitotak          #+#    #+#             */
/*   Updated: 2026/01/04 17:43:33 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	does_include_nl(char *s)
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
	static t_gnl	*stash = NULL;
	t_gnl			*node;
	char			*buf;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = NULL;
	print
	node = get_save_from_stash(&stash, fd);
	while (does_include_nl(node->save) == 0)
	{
		buf = read_to_buf(buf, fd);
		if (buf == NULL)
			return (ret_cpy_free(&buf, &node->save));
		else if (buf[0] == '\0')
			return (ret_cpy_free(&node->save, &buf));
		node->save = add_to_save(node->save, buf);
		if (node->save == NULL)
			return (ret_cpy_free(&node->save, &buf));
	}
	line = ft_substr(node->save, 0, does_include_nl(node->save));
	node->save = trans_save(node->save, node->save + does_include_nl(node->save));
	return (ret_cpy_free(&line, &buf));
}

//		if (rc < BUFFER_SIZE)
//			return (ret_cpy(save));
