/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:39:56 by keitotak          #+#    #+#             */
/*   Updated: 2025/11/05 16:17:19 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_nl
{
	char	*ptr;
	size_t	len;
}				t_nl;

typedef struct s_rd
{
	char	*buf;
	size_t	rc;
}				t_rd;

char	*get_next_line(int fd);
char	*ft_read(int fd);
char	*ft_save_add(char *save, char *add);
t_nl	*ft_get_nl(char *s, t_nl *nl);
char	*ft_get_line(char *save, size_t len);
char	*ft_save_trans(char *save, char *start);
char	*ft_free(char *s, void *ptr);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
