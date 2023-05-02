/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/02 20:40:46 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"


t_cast	horizontal_raycast(t_cube *cube)
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
		r.y = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
		r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
		r.yo = -cube->ts;
		r.xo = -r.yo * a_tan;
	}
	if (r.a > 0 && r.a < PI)
	{
		r.y = (p_map_pos(cube, 'y') * cube->ts) + (cube->ts / 2);
		r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
		r.yo = cube->ts;
		r.xo = -r.yo * a_tan;
	}
	if (p.vec.y == 0)
	{
		r.x = p.pos.x;
		r.y = p.pos.y;
		offset = cube->map_height;
	}
	while (offset < cube->map_height - 1)
	{
		r.mx = (int)(r.x + cube->ts / 2) / cube->ts;
		r.my = (int)(r.y) / cube->ts;
		if (p.vec.y < 0 && is_in_map(cube, r.mx, r.my) == 1
			&& cube->map[r.my][r.mx] == '1')
			offset = cube->map_height;
		else if (p.vec.y > 0 && is_in_map(cube, r.mx, r.my) == 1
			&& cube->map[r.my + 1][r.mx] == '1')
			offset = cube->map_height;
		else
		{
			r.x += r.xo;
			r.y += r.yo;
			offset++;
		}
	}
	r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
			+ (r.y - p.pos.y) * (r.y - p.pos.y));
	return (r);
}

t_cast	vertical_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;
	int			offset;

	p = cube->p;
	offset = 0;
	r.a = p.angle;
	a_tan = -tan(r.a);
	if (p.vec.x > 0)
	{
		r.x = p_map_pos(cube, 'x') * cube->ts + (cube->ts / 2);
		r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
		r.xo = -cube->ts;
		r.yo = -r.xo * a_tan;
	}
	if (p.vec.x < 0)
	{
		r.x = (p_map_pos(cube, 'x') * cube->ts) - (cube->ts / 2);
		r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
		r.xo = cube->ts;
		r.yo = -r.xo * a_tan;
	}
	else if (p.vec.x == 0)
	{
		r.y = p.pos.y;
		r.x = p.pos.x;
		offset = cube->max_line_size;
	}
	while (offset < cube->max_line_size - 1)
	{
		r.my = (int)(r.y + cube->ts / 2) / cube->ts;
		r.mx = (int)(r.x) / cube->ts + 1;
		if (p.vec.x > 0 && is_in_map(cube, r.mx, r.my) == 1
			&& cube->map[r.my][r.mx] == '1')
			offset = cube->max_line_size;
		else if (p.vec.x < 0 && is_in_map(cube, r.mx, r.my) == 1
			&& cube->map[r.my][r.mx - 1] == '1')
			offset = cube->max_line_size;
		else
		{
			r.y -= r.yo;
			r.x -= r.xo;
			offset++;
		}
	}
	r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
			+ (r.y - p.pos.y) * (r.y - p.pos.y));
	return (r);
}

void	draw_closest_ray(t_cube *cube)
{
	t_cast	v_ray;
	t_cast	h_ray;

	h_ray = horizontal_raycast(cube);
	v_ray = vertical_raycast(cube);

	if (h_ray.size <= v_ray.size)
		draw_segment(cube, cube->p.pos, (t_point){h_ray.x, h_ray.y}, 65280);
	else
		draw_segment(cube, cube->p.pos, (t_point){v_ray.x, v_ray.y}, 65280);
}
