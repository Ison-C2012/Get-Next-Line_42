/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:46:52 by keitotak          #+#    #+#             */
/*   Updated: 2025/10/27 16:26:43 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*get_str(char *str, long n)
{
	size_t	i;

	i = get_len(n);
	str[i--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[i--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((get_len((long)n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (get_str(str, (long)n));
}
