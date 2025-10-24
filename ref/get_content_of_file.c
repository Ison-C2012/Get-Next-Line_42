/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_of_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:42:20 by keitotak          #+#    #+#             */
/*   Updated: 2025/08/28 05:52:04 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_size_of_file(char *file)
{
	int		size;
	int		read_count;
	int		fd;
	char	buf[BUF_SIZE];

	size = 0;
	read_count = 1;
	if (file == NULL)
		fd = STDIN_FILENO;
	else
		fd = open(file, O_RDONLY);
	while (read_count)
	{
		read_count = read(fd, buf, BUF_SIZE);
		if (read_count == -1)
			return (-1);
		size += read_count;
	}
	if (fd != STDIN_FILENO)
		close(fd);
	return (size);
}

char	*read_a_file(char *file)
{
	char	*content;
	int		size;
	int		fd;

	size = get_size_of_file(file);
	if (size == -1)
		return (NULL);
	content = (char *)malloc(sizeof(char) * (size + 1));
	if (content == NULL)
		return (NULL);
	if (file == NULL)
		fd = STDIN_FILENO;
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read(fd, content, size) == -1)
		return (NULL);
	close(fd);
	content[size] = '\0';
	return (content);
}

char	**save_input(char *content)
{
	char	**input;

	input = ft_split(content, "\n\0");
	if (input == NULL)
		return (NULL);
	free(content);
	return (input);
}

char	**get_content_of_file(char *file)
{
	char	*content;
	char	**input;

	content = read_a_file(file);
	if (content == NULL)
		return (NULL);
	input = save_input(content);
	if (input == NULL)
		return (NULL);
	return (input);
}
