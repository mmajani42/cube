/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/05 06:09:59 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

t_point	get_player_vec(char direction)
{
	t_point	res;

	res.x = 0;
	res.y = 0;
	if (direction == 'N')
		res.y = -1;
	if (direction == 'S')
		res.y = 1;
	if (direction == 'E')
		res.x = 1;
	if (direction == 'W')
		res.x = -1;
	return (res);
}

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
			if (ft_strchr("NSEW", map[y][x]) != NULL)
			{
				res.x = x;
				res.y = y;
				return (res);
			}
			x++;
		}
		y++;
	}
	if (!map[y])
		print_error("No player found in map description");
	return (res);
}

void	get_player_coordinates(t_player *p, char **map)
{
	p->pos = get_player_pos(map);
	if (p->pos.x > -1 && p->pos.y > -1)
		p->vec = get_player_vec(map[(int)p->pos.y][(int)p->pos.x]);
	else
	{
		p->vec.x = 0;
		p->vec.y = 0;
	}
}

int	parsing(char *filename, t_cube *cube)
{
	init_cube(cube);
	cube->file = file_to_tab(filename);
	if (!cube->file)
		return (0);
	if (!parse_elements(cube) || !parse_description(cube))
	{
		free_cube(cube);
		return (0);
	}
	return (1);
}
