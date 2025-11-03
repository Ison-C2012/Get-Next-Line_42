/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/03 14:55:46 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*get_line_to_eof(char *stk)
{
	char	*line;

	line = ft_substr(stk, 0, SIZE_MAX);
	free(stk);
	stk = malloc(1);
	if (stk == NULL)
		return (NULL);
	ft_memset(stk, 0, 1);
	return (line);
}

char	*get_line_to_nl(char *stk, char *buf)
{
	char	*line_to_add;
	char	*line;

	line_to_add = ft_substr(buf, 0, (ptr - buf) + 1);
	if (line_to_add == NULL)
		return (NULL);
	line = ft_strjoin(stk, line_to_add);
	free(line_to_add);
	if (*stk)
		free(stk);
	stk = ft_substr(buf, (ptr - buf) + 1, BUFFER_SIZE);
	if (stk == NULL)
		return (NULL);
	return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = "";
	char		*buffer;
	int			read_count;
	char		*next_line;
	char		*ptr;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		ptr = ft_memchr(buf, '\n', BUFFER_SIZE);
		if (ptr)
			return (get_line_to_nl(stock, buffer));
		if (*next_line)
			return (next_line);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	}
	if (*stock == '\0')
		return (NULL);
	free(buffer);
	return (get_line_to_eof(stock));
}
