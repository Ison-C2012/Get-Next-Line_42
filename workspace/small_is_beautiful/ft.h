
#ifndef SMALL_IS_BEAUTIFUL_H
#define SMALL_IS_BEAUTIFUL_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct	s_nl
{
	char	*ptr;
	size_t	len_to;
	size_t	len_from;
}				t_nl;

char	*ft_process(int fd);
char	*ft_read(int fd);
char	*ft_save_add(char *save, char *add);
t_nl	*ft_get_nl(char *s, t_nl *nl);
char	*ft_get_line(char *save, size_t len);
char	*ft_save_trans(char *save, t_nl *nl);
char	*ft_free_nl(t_nl *nl);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif
