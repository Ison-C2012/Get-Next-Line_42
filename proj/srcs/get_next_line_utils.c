/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:30:45 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/03 01:14:30 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		ptr[n] = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	m_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	m_size = nmemb * size;
	mem = malloc(m_size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, m_size);
	return (mem);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len++])
		;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*j;

	s1_len = 0;
	while (s1[s1_len++])
		;
	s2_len = 0;
	while (s2[s2_len++])
		;
	j = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (j == NULL)
		return (NULL);
	ft_strlcpy(j, s1, s1_len + 1);
	ft_strlcpy(j + s1_len, s2, s2_len + 1);
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	s_len;
	size_t	sb_len;

	s_len = 0;
	while (s[s_len++])
		;
	if (len == 0 || start > s_len)
		return (NULL);
	if (start + len > s_len)
		sb_len = s_len - start;
	else
		sb_len = len;
	sb = (char *)malloc((sb_len + 1) * sizeof(char));
	if (sb == NULL)
		return (NULL);
	ft_strlcpy(sb, s + start, sb_len + 1);
	return (sb);
}
