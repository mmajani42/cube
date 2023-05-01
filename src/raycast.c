/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/01 19:22:00 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

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

void	draw_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;

	p = cube->p;
	r.a = p.angle;
	a_tan = -1 / tan(r.a);
	if (p.vec.y < 0)
	{
		r.y = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
		r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
		dprintf(1, "ra= %.2f\tvec.x= %.2f\tvec.y= %.2f\t r.y= %.2f\t r.x= %.2f\n", r.a, p.vec.x, p.vec.y, r.y, r.x);
		draw_dot(cube, r.x, r.y);
		// draw_segment(cube, p.pos, (t_point){p.pos.x + r.x, p.pos.y + r.y}, 16777215);

	}
}
