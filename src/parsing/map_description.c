/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/04 18:47:13 by vimercie         ###   ########lyon.fr   */
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
	return (1);
}

int	init_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (!is_valid_map_line(cube->file[i]))
		i++;
	if (!cube->file[i])
		return (print_error("No map description"));
	if (!get_map_dimensions(cube->file + i, cube))
		return (print_error("Bad map description"));
	j = 0;
	cube->map = ft_calloc(cube->map_height + 1, sizeof(char *));
	while (cube->file[i])
	{
		cube->map[j] = dup_and_fill(cube->file[i], ' ', cube->max_line_size,
				cube->file[i][ft_strlen(cube->file[i]) - 1] == '\n');
		i++;
		j++;
	}
	return (1);
}

int	parse_description(t_cube *cube)
{
	if (!init_map(cube))
		return (0);
	if (!is_map_bordered(cube->map))
		return (print_error("Map is not surrounded by walls"));
	return (1);
}
