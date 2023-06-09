/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:04:30 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/07 12:01:47 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	set_angles(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < RES)
	{
		cube->angles[i] = -atan((RES / 2 - i + 0.5) / RES / 2);
		i++;
	}
}

double	reset_angle(double angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

int	p_map_pos(t_cube *cube, char c)
{
	t_point	pos;

	if (c == 'x')
	{
		pos.x = (int)((cube->p.pos.x + (cube->ts / 2)) / cube->ts);
		return (pos.x);
	}
	if (c == 'y')
	{
		pos.y = (int)((cube->p.pos.y + (cube->ts / 2)) / cube->ts);
		return (pos.y);
	}
	return (0);
}

int	is_in_map(t_cube *cube, int x, int y)
{
	if ((x >= 0 && x < cube->map_width) && y >= 0 && y < cube->map_height)
		return (1);
	return (0);
}
