/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:45:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 02:51:54 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	*get_texture_path(char *line)
{
	char	*res;

	res = get_next_word(line);
	if (!res)
		return (NULL);
	if (!check_file_extension(res, ".xpm"))
	{
		print_error("Invalid asset format", res);
		free(res);
		return (NULL);
	}
	if (access(res, R_OK) == -1)
	{
		print_error(NULL, NULL);
		perror(res);
		free(res);
		return (NULL);
	}
	return (res);
}

int	get_fd(char *filename)
{
	int	fd;

	if (!check_file_extension(filename, ".cub"))
	{
		print_error("Invalid argument format (*.cub required)", filename);
		return (-1);
	}
	if (access(filename, R_OK) == -1)
	{
		print_error(NULL, NULL);
		perror(filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL, NULL);
		perror(filename);
	}
	return (fd);
}
