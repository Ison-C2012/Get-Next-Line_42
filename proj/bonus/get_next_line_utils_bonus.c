/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:30:45 by keitotak          #+#    #+#             */
/*   Updated: 2026/01/04 17:43:39 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save_from_stash(t_gnl *stash, int fd)
{
	while (stash != NULL)
	{
		if (stash->fd == fd)
			return (stash->save);
		stash = stash->next;
	}
	stash = (t_gnl *)malloc(sizeof(t_gnl));
	if (stash == NULL)
		return (NULL);
	stash->save = NULL;
	stash->fd = fd;
	stash->next = NULL;
	return (stash->save);
}

char	*ret_cpy_free(char **to_ret, char **to_free)
{
	char	*line;

	line = *to_ret;
	*to_ret = NULL;
	free(*to_free);
	*to_free = NULL;
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
		str[i++] = *s1++;
	while (i < s1_len + s2_len)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	sb_len;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start > s_len)
		return (NULL);
	if (start + len > s_len)
		sb_len = s_len - start;
	else
		sb_len = len;
	sb = (char *)malloc((sb_len + 1) * sizeof(char));
	if (sb == NULL)
		return (NULL);
	i = 0;
	while (i < sb_len)
		sb[i++] = *(s++ + start);
	sb[i] = '\0';
	return (sb);
}
