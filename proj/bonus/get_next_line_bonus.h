/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:39:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/01/04 17:41:33 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct s_gnl
{
	char			*save;
	int				fd;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
char	*ret_cpy_free(char **to_ret, char **to_free);

t_gnl	*get_save_from_stash(t_gnl **stash, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
