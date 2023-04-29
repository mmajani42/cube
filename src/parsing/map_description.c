/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 18:06:26 by vimercie         ###   ########lyon.fr   */
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

char	**map_cpy(char **file, int height)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc(height + 1, sizeof(char *));
	while (file[i])
	{
		res[i] = file[i];
		i++;
	}
	return (res);
}

int	parse_description(char **file, t_cube *cube)
{
	while (!is_valid_map_line(file[0]) && file[0])
		file++;
	if (!file[0])
		return (print_error("No map description"));
	while (file[cube->map_height])
	{
		if (!is_valid_map_line(file[cube->map_height]))
			return (print_error("Invalid map description"));
		cube->map_height++;
	}
	cube->map = file;
	cube->max_line_size = get_max_line_size(cube->map);
	return (1);
}
