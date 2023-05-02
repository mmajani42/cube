/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/02 20:47:01 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

t_point	get_player_pos(char **map)
{
	t_point		res;
	int			x;
	int			y;

	y = 0;
	res.x = -1;
	res.y = -1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N'
				|| map[y][x] == 'S'
				|| map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				res.x = x;
				res.y = y;
				// res.vec = get_player_vec();
				return (res);
			}
			x++;
		}
		y++;
	}
	return (res);
}

bool	is_map_bordered(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((ft_isspace(map[y][x]) || x == 0)
				&& !wall_sonar(x, y, map))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int	parse_description(char **file, t_cube *cube)
{
	int	i;

	i = 0;
	while (!is_valid_map_line(file[i]) && file[i])
		i++;
	if (!file[i])
		return (print_error("No map description"));
	cube->map_height = i;
	while (file[cube->map_height])
	{
		if (!is_valid_map_line(file[cube->map_height]))
			return (print_error("Invalid map description"));
		cube->map_height++;
	}
	cube->map = file + i;
	cube->max_line_size = get_max_line_size(cube->map);
	printf("border_integrity = %d\n", is_map_bordered(cube->map));
	return (1);
}
