/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_all_in_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/04 17:22:11 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stk = "";
	char		*buf;
	int			rc;
	char		*ptr;
	char		*line_to_res;
	char		*line_to_cat;
	char		*tmp;
	
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	rc = 1;
	while (rc)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rc] = '\0';
		line_to_cat = NULL;
		line_to_res = NULL;
		if (ft_strchr(stk, '\n'))
		{
			ptr = ft_strchr(stk, '\n');
			line_to_res = ft_substr(stk, 0, ptr - stk + 1);
			tmp = ft_substr(ptr, 1, BUFFER_SIZE);
			if (*stk)
				free(stk);
			stk = tmp;
		}
		else if (ft_strchr(buf, '\n'))
		{
			ptr = ft_strchr(buf, '\n');
			line_to_cat = ft_substr(buf, 0, ptr - buf + 1);
			if (line_to_cat == NULL)
				return (NULL);
			line_to_res = ft_strjoin(stk, line_to_cat);
			free(line_to_cat);
			tmp = ft_substr(ptr, 1, BUFFER_SIZE);
			if (*stk)	//if "" is allocated memory, they leaks.
				free(stk);
			stk = tmp;
			return (line_to_res);
		}
		else
		{
			tmp = ft_strjoin(stk, buf);
			if (*stk)	//if "" is allocated memory, they leaks.
				free(stk);
			stk = tmp;
		}
		if (stk == NULL)
		{
			free(buf);
			return (NULL);
		}
		if (line_to_res)
		{
			free(buf);
			return (line_to_res);
		}
	}
	free(buf);
	return (stk);
}
