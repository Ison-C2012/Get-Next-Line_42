/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/02 18:42:19 by keitotak         ###   ########.fr       */
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

char	*get_one_line(char *stk, char *buf, size_t len)
{
	char	*line;
	char	*tmp;

	tmp = ft_substr(buf, 0, len + 1);
	if (tmp == NULL)
		return (NULL);
	line = ft_strjoin(stk, tmp);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = malloc(1);
	int		read_count;
	char	buf[BUFFER_SIZE];
	char	*ptr_nl;
	char	*tmp;
	char	*next_line;

	stock = (char *)malloc(1 * sizeof(char));
	if (stock == NULL)
		return (NULL);
	stock[0] = '\0';
	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		ptr_nl = ft_memchr(buf, '\n', BUFFER_SIZE);
		if (ptr_nl)
		{
			next_line = get_one_line(stock, buf, ptr_nl - buf);
			tmp = stock;
			stock = ptr_nl + 1;
			tmp[ptr_nl - buf] = '\0';
			free(tmp);
			return (next_line);
		}
		stock = ft_strjoin(stock, buf);
		if (stock == NULL)
			return (NULL);
		ft_memset(buf, 0, BUFFER_SIZE);
	}
	if (*buf)
		return (ft_strjoin(stock, buf));
	return (NULL);
}
