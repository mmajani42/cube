/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 15:22:43 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

#define TEXTURE 1
#define COLOR 2
#define MAP 3

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	parsing_selector(char *s)
{
	if (s[0] == 'N' || s[0] == 'S' || s[0] == 'W' || s[0] == 'E')
		return (TEXTURE);
	else if (s[0] == 'F' || s[0] == 'C')
		return (COLOR);
	else if (s[0] == '1')
		return (MAP);
	return (0);
}

// int	parse_line(char *str, t_cube *cube)
// {
	
// }

bool	is_wall(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] == ' ' || line[i] == '1')
		i++;
	if (line[i] == '\n' && i >= 2)
		return (true);
	return (false);
}

int	count_map_lines(char *filename)
{
	char	*buffer;
	int		map_fd;
	bool	is_map;
	int		res;

	res = 0;
	is_map = 0;
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		ft_putstr_fd("unvalid map\n", STDERR_FILENO);
	buffer = get_next_line(map_fd);
	while (buffer)
	{
		if (is_wall(buffer))
			is_map = 1;
		if (is_map)
			res++;
		free(buffer);
		buffer = get_next_line(map_fd);
	}
	close(map_fd);
	return (res);
}

char	**get_map(char *filename, int map_height)
{
	char	**res;
	char	*buffer;
	int		map_fd;
	bool	is_map;
	int		i;

	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		ft_putstr_fd("unvalid map\n", STDERR_FILENO);
	res = ft_calloc(map_height + 1, sizeof(char *));
	buffer = get_next_line(map_fd);
	is_map = false;
	i = 0;
	while (buffer)
	{
		if (is_wall(buffer))
			is_map = true;
		if (is_map)
		{
			res[i] = ft_strdup(buffer);
			i++;
		}
		free(buffer);
		buffer = get_next_line(map_fd);
	}
	return (res);
}

int	count_lines(char *filename)
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
	res = ft_calloc(count_lines(filename) + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		res[i] = ft_strdup(buffer);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (res);
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

int	parsing(char *filename, t_cube *cube)
{
	char	**file;

	file = file_to_tab(filename);
	parse_elements(file, cube);
	cube->map_height = count_map_lines(filename);
	cube->map = get_map(filename, cube->map_height);
	cube->max_line_size = get_max_line_size(cube->map);
	// free_tab(cube->map);
	return (1);
}
