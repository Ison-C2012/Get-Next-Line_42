/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/01 17:24:32 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	int		read_count;
	char	buf[BUFFER_SIZE];
	char	*p_nl;
	char	*line;

	stock = (char *)malloc(1 * sizeof(char));
	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		p_nl = ft_strchr(buf, '\n');
		if (p_nl)
		{
			tmp = ft_substr(buf, 0, p_nl - buf + 1);
			if (tmp == NULL)
				return (NULL);
			line = ft_strjoin(stk, tmp);
			free(tmp);
			ft_memset(stk, 0, ft_strlen(stk));
			return (line);
		}
		stk = ft_strjoin(stk, p_nl);
		if (stk == NULL)
			return (NULL);
	}
	ft_memset(stk, 0, ft_strlen(stk));
	return (NULL);
}

