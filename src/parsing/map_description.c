/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/06 20:51:49 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	get_map_dimensions(char **file, t_cube *cube)
{
	while (file[cube->map_height])
	{
		if (!is_valid_map_line(file[cube->map_height]))
			return (0);
		if ((int)ft_strlen(file[cube->map_height]) > cube->max_line_size)
		{
			cube->max_line_size = (int)ft_strlen(file[cube->map_height]);
			if (file[cube->map_height][cube->max_line_size - 1] == '\n')
				cube->max_line_size--;
		}
		cube->map_height++;
	}
	if (cube->map_height < 3)
		return (0);
	return (1);
}

int	map_cpy(char **file, t_cube *cube)
{
	int	len;
	int	i;

	i = 0;
	cube->map = ft_calloc(cube->map_height + 1, sizeof(char *));
	while (file[i])
	{
		len = ft_strlen(file[i]);
		cube->map[i] = dup_and_fill(file[i], ' ', cube->max_line_size,
				file[i][len - 1] == '\n');
		i++;
	}
	return (1);
}

int	init_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (!is_valid_map_line(cube->file[i]))
		i++;
	if (!cube->file[i])
		return (print_error("No map description"));
	if (!get_map_dimensions(cube->file + i, cube))
		return (print_error("Bad map description"));
	if (!map_cpy(cube->file + i, cube))
		return (0);
	return (1);
}

int	parse_description(t_cube *cube)
{
	if (!init_map(cube))
		return (0);
	if (!is_map_bordered(cube->map))
		return (print_error("Map is not surrounded by walls"));
	if (!is_unique_player(cube->map))
		return (print_error("One player required"));
	return (1);
}
