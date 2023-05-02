/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/02 14:57:12 by mmajani          ###   ########lyon.fr   */
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

int		is_in_map(t_cube *cube, int x, int y)
{
	if ((x >= 0 && x < cube->max_line_size) && y >= 0 && y < cube->map_height)
		return (1);
	return (0);
}

int		horizontal_detection(t_cube *cube)
{
	
}

void	draw_raycast_2(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;
	int			offset;

	p = cube->p;
	offset = 0;
	r.a = p.angle;
	a_tan = -1 / tan(r.a);
	if (r.a < 0 && r.a > -PI)
	{
		dprintf(1, "A\n");
		r.y = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
		r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
		r.yo = -cube->ts;
		r.xo = -r.yo * a_tan;
		draw_dot(cube, r.x, r.y);
	}
	if (r.a > 0 && r.a < PI)
	{
		dprintf(1, "BEFORE\nr.x = %.2f\t\tr.y = %.2f\t\tr.a = %.2f\n", r.x, r.y, r.a);
		r.y = (p_map_pos(cube, 'y') * cube->ts) + (cube->ts / 2);
		r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
		r.yo = cube->ts;
		r.xo = -r.yo * a_tan;
		draw_dot(cube, r.x, r.y);
		dprintf(1, "AFTER\nr.x = %.2f\t\tr.y = %.2f\t\tr.a = %.2f\n\n", r.x, r.y, r.a);
	}
	if (p.vec.y == 0)
	{
		dprintf(1, "C\n");
		r.x = p.pos.x;
		r.y = p.pos.y;
		offset = cube->map_height;
	}
//	dprintf(1, "r.my = %d\tr.mx = %d\n", r.my, r.mx);
	while (offset < cube->map_height - 1)
	{
		r.mx = (int)(r.x + cube->ts / 2) / cube->ts;
		r.my = (int)(r.y) / cube->ts;
		if (p.vec.y < 0 && is_in_map(cube, r.mx, r.my) == 1 && cube->map[r.my][r.mx] == '1')
			offset = cube->map_height;
		else if (p.vec.y > 0 && is_in_map(cube, r.mx, r.my) == 1 && cube->map[r.my + 1][r.mx] == '1')
			offset = cube->map_height;
		else
		{
			r.x += r.xo;
			r.y += r.yo;
			offset++;
		}
		draw_dot(cube, r.x, r.y);
		if (sqrt(((r.x - p.pos.x) * (r.x - p.pos.x)) + (r.y - p.pos.y) * (r.y - p.pos.y)) < 3000)
			draw_segment(cube, p.pos, (t_point){r.x, r.y}, 65280);
		offset++;
	}
}

void	draw_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;
	int			offset;

	p = cube->p;
	offset = 0;
	r.a = p.angle;
	a_tan = -tan(r.a);
	if (p.vec.x < 0)
	{
		dprintf(1, "A\n");
		r.x = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
		r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
		r.xo = -cube->ts;
		r.yo = -r.xo * a_tan;
		draw_dot(cube, r.x, r.y);
	}
	if (p.vec.x > 0)
	{
		dprintf(1, "BEFORE\nr.x = %.2f\t\tr.y = %.2f\t\tr.a = %.2f\n", r.x, r.y, r.a);
		r.x = (p_map_pos(cube, 'y') * cube->ts) + (cube->ts / 2);
		r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
		r.xo = cube->ts;
		r.yo = -r.xo * a_tan;
		draw_dot(cube, r.x, r.y);
		dprintf(1, "AFTER\nr.x = %.2f\t\tr.y = %.2f\t\tr.a = %.2f\n\n", r.x, r.y, r.a);
	}
	if (p.vec.y == 0)
	{
		dprintf(1, "C\n");
		r.x = p.pos.x;
		r.y = p.pos.y;
		offset = cube->map_height;
	}
//	dprintf(1, "r.my = %d\tr.mx = %d\n", r.my, r.mx);
	while (offset < cube->map_height - 1)
	{
		r.my = (int)(r.y + cube->ts / 2) / cube->ts;
		r.mx = (int)(r.x) / cube->ts;
		if (p.vec.x < 0 && is_in_map(cube, r.mx, r.my) == 1 && cube->map[r.my][r.mx] == '1')
			offset = cube->map_height;
		else if (p.vec.x > 0 && is_in_map(cube, r.mx, r.my) == 1 && cube->map[r.my][r.mx - 1] == '1')
			offset = cube->map_height;
		else
		{
			r.x += r.xo;
			r.y += r.yo;
			offset++;
		}
		draw_dot(cube, r.x, r.y);
		if (sqrt(((r.x - p.pos.x) * (r.x - p.pos.x)) + (r.y - p.pos.y) * (r.y - p.pos.y)) < 3000)
			draw_segment(cube, p.pos, (t_point){r.x, r.y}, 65280);
		offset++;
	}
}
