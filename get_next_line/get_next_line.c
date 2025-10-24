/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:04 by keitotak          #+#    #+#             */
/*   Updated: 2025/10/24 21:59:06 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ON 1
#define OFF 0

static size_t	getlen_nl(int fd)
{
	size_t	len;
	int		read_mode;

	len = 0;
	read_mode = ON;
	while
}

char	*get_next_line(int fd)
{
	size_t	len;
	char	*nl;

	nl = (char *)malloc((getlen_nl(fd) + 1) * sizeof(char));
	if (nl == NULL)
		return (NULL);
	if (read(fd, nl, len) == -1)
		return (NULL);
	nl[len] = '\0';
	return (nl);
}

