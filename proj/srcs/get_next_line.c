/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/03 21:37:22 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_buf_res_s(char *buffer, char *s)
{
	free(buffer);
	return (s);
}

static char	*get_nl_in_stock(char *stock, char *buffer)
{
	char	*ptr;
	char	*line_to_res;
	char	*tmp;

	ptr = ft_memchr(stock, '\n', BUFFER_SIZE);
	line_to_res = ft_substr(stock, 0, ptr - stock + 1);
	tmp = stock;
	stock = ft_substr(ptr, 1, BUFFER_SIZE);
	free(tmp);
	return (free_buf_res_s(buffer, line_to_res));
}

static char	*get_nl_in_buffer(char *buffer, char *stock, size_t read_count)
{
	char	*ptr;
	char	*line_to_res;
	char	*line_to_cat;

	ptr = ft_memchr(buffer, '\n', read_count);
	line_to_cat = ft_substr(buffer, 0, ptr - buffer + 1);
	if (line_to_cat == NULL)
		return (free_buf_res_s(buffer, NULL));
	line_to_res = ft_strjoin(stock, line_to_cat);
	free(line_to_cat);
	if (*stock)	//if "" is allocated memory, they leaks.
		free(stock);
	stock = ft_substr(ptr, 1, read_count);
	return (free_buf_res_s(buffer, line_to_res));
}

static void	charge_to_stock(char *stock, char *buffer)
{
	char	*tmp;

	tmp = stock;
	stock = ft_strjoin(stock, buffer);
	if (*tmp)	//if "" is allocated memory, they leaks.
		free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*stock = "";
	char		*buffer;
	int			read_count;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free_buf_res_s(buffer, NULL));
		buffer[read_count] = '\0';
		if (ft_memchr(stock, '\n', BUFFER_SIZE))
			return (get_nl_in_stock(stock, buffer));
		else if (ft_memchr(buffer, '\n', read_count))
			return (get_nl_in_buffer(buffer, stock, read_count));
		else
			charge_to_stock(stock, buffer);
		if (stock == NULL)
			return (free_buf_res_s(buffer, NULL));
	}
	return (free_buf_res_s(buffer, stock));
}
