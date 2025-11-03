/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:05:24 by keitotak          #+#    #+#             */
/*   Updated: 2025/10/26 15:35:16 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	l_len = ft_strlen(little);
	while (*big && len >= l_len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
