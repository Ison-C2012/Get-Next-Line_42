/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/10/25 16:13:04 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFSIZE 4096 

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*get_content_of_file(int fd)
{
	size_t	len;
	int		read_count;
	char	buf[BUFSIZE];
	char	*content;

	len = 0;
	read_count = 0;
	while (read_count)
	{
		read_count = read(fd, buf, 42);
		if (read_count == -1)
			return (NULL);
		len += read_count;
	}
	printf("read_count:%d\n", read_count);
	printf("len:%zu\n", len);
	content = (char *)malloc((len + 1) * sizeof(char));
	if (content == NULL)
		return (NULL);
	ft_strlcpy(content, buf, len + 1);
	return (content);
}

size_t	get_length_of_line(char *buf)
{
	size_t	len;

	len = 0;
	while (*buf != '\0' && *buf != '\n')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	size_t	len;

	buf = get_content_of_file(fd);
	return (buf);
	if (buf == NULL)
		return (NULL);
	len = get_length_of_line(buf);
	line = (char *)malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buf, len + 1);
	return (line);
}

