/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 01:41:49 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	*dup_and_fill(char *src, char c, size_t size, bool ow_last_char)
{
	char	*res;
	size_t	len;

	if (!src || !size)
		return (NULL);
	len = ft_strlen(src) - ow_last_char;
	if (len <= 0)
		return (NULL);
	if (len >= size)
		return (ft_strndup(src, size));
	res = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(res, src, len + 1);
	memset(res + len, c, size - len);
	return (res);
}

int	map_cpy(char **file, t_cube *cube)
{
	int	len;
	int	i;

	cube->map = ft_calloc(cube->map_height + 1, sizeof(char *));
	if (!cube->map)
		return (print_error("Malloc failed", NULL));
	i = 0;
	while (file[i])
	{
		len = ft_strlen(file[i]);
		cube->map[i] = dup_and_fill(file[i], ' ', cube->map_width,
				file[i][len - 1] == '\n');
		i++;
	}
	return (1);
}

int	get_map_dimensions(char **file, t_cube *cube)
{
	while (file[cube->map_height])
	{
		if (!is_valid_map_line(file[cube->map_height]))
			return (0);
		if ((int)ft_strlen(file[cube->map_height]) > cube->map_width)
		{
			cube->map_width = (int)ft_strlen(file[cube->map_height]);
			if (file[cube->map_height][cube->map_width - 1] == '\n')
				cube->map_width--;
		}
		cube->map_height++;
	}
	if (cube->map_height < 3)
		return (0);
	return (1);
}

int	init_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (!is_valid_map_line(cube->file[i]))
		i++;
	if (!cube->file[i])
		return (print_error("No map description", NULL));
	if (!get_map_dimensions(cube->file + i, cube))
		return (print_error("Bad map description", NULL));
	if (!map_cpy(cube->file + i, cube))
		return (0);
	return (1);
}

int	parse_description(t_cube *cube)
{
	if (!init_map(cube))
		return (0);
	if (!is_map_bordered(cube->map))
		return (print_error("Map is not surrounded by walls", NULL));
	if (!is_unique_player(cube->map))
		return (print_error("One player required", NULL));
	return (1);
}
