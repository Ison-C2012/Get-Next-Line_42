


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void	init(char **stk)
{
	char	*tmp;

	tmp = malloc(1);
	tmp[0] = '\0';
	*stk = tmp;
}

char	*ft_concatenate(char *s)
{
	static char *stk;

	init(&stk);
	stk = ft_strjoin(stk, s);
	if (stk)
		return (stk);
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_concatenate("Hi,"));
	printf("%s\n", ft_concatenate(" I'm"));
	printf("%s\n", ft_concatenate(" Keito"));
	printf("%s\n", ft_concatenate("."));
}
