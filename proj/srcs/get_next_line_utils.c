/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:30:45 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/02 16:15:00 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		ptr[n] = (unsigned char)c;
	return (s);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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

	s_len = ft_strlen(s);
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
