/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:49:14 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 16:17:00 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	*get_next_word(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	while (ft_isspace(str[0]) && str[0] != '\n' && str[0])
		str++;
	while (!ft_isspace(str[len]) && str[len])
		len++;
	if (len == 0)
		return (NULL);
	return (ft_strndup(str, len));
}

size_t	get_max_line_size(char **map)
{
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > res)
			res = ft_strlen(map[i]);
		i++;
	}
	return (res);
}

int	count_file_lines(char *filename)
{
	char	*buffer;
	int		res;
	int		fd;

	fd = open(filename, O_RDONLY);
	res = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		res++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (res);
}

char	**file_to_tab(char *filename)
{
	char	**res;
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	res = ft_calloc(count_file_lines(filename) + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		res[i] = ft_strdup(buffer);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (res);
}
