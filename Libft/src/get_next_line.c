/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:40:44 by vimercie          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:59 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	line_join(char *buf, char **line, int *index)
{
	char	*tmp;

	if (!newline_chr(buf, *index) && buf[*index] != '\n')
	{
		tmp = gnl_substr(buf, *index, ft_strlen(buf) - *index);
		*line = gnl_strjoin(*line, tmp);
		*index = 0;
	}
	else
	{
		tmp = gnl_substr(buf, *index, (newline_chr(buf, *index) + 1) - *index);
		*line = gnl_strjoin(*line, tmp);
		if (buf[newline_chr(buf, *index) + 1])
			*index = newline_chr(buf, *index) + 1;
		else
			*index = 0;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	index;
	char		*line;
	int			is_read;

	line = NULL;
	is_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (is_read > 0)
	{
		if (index == 0)
		{
			is_read = read(fd, buf, BUFFER_SIZE);
			if (is_read == -1)
				return (NULL);
			buf[is_read] = '\0';
		}
		if (is_read == 0)
			return (line);
		if (line_join(buf, &line, &index) == 1)
			return (line);
	}
	return (line);
}
