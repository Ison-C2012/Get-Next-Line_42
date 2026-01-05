
#include "ft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

	if (len == 0)
		return (NULL);
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
