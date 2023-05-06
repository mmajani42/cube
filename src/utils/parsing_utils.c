/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:49:14 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/06 20:42:08 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	*dup_and_fill(char *src, char c, int size, bool ow_last_char)
{
	char	*res;
	size_t	len;

	res = ft_calloc(size + 1, sizeof(char));
	len = ft_strlen(src) - ow_last_char;
	ft_strlcpy(res, src, len + 1);
	memset(res + len, c, size - len);
	return (res);
}

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

int	get_fd(char *filename)
{
	int	fd;

	if (!check_file_extension(filename, ".cub"))
	{
		print_error("Invalid argument format (*.cub required)");
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		print_error(NULL);
		perror(filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL);
		perror(filename);
	}
	return (fd);
}

int	count_file_lines(char *filename)
{
	char	*buffer;
	int		fd;
	int		res;

	res = 0;
	fd = get_fd(filename);
	buffer = get_next_line(fd);
	while (buffer)
	{
		res++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (res);
}

char	**file_to_tab(char *filename)
{
	char	**res;
	char	*buffer;
	int		fd;
	int		file_height;
	int		i;

	i = 0;
	file_height = count_file_lines(filename);
	if (file_height == 0)
		return (NULL);
	fd = get_fd(filename);
	buffer = get_next_line(fd);
	res = ft_calloc(file_height + 1, sizeof(char *));
	while (buffer)
	{
		res[i] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	close(fd);
	return (res);
}
