/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/04 14:05:08 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define DR	0.0174533

void	horizontal_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;
	int			offset;
	int			i;

	i = 0;
	p = cube->p;
	r.a = p.angle - ((FOV / 2) * DR);
	if (r.a < 0)
		r.a += 2 * PI;
	if (r.a >= 2 * PI)
		r.a -= 2 * PI;
	while (i < FOV)
	{
		offset = 0;
		a_tan = -1 / tan(r.a);
		if (sin(r.a) < 0) // Looking UP
		{
			r.y = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
			r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
			r.yo = -cube->ts;
			r.xo = -r.yo * a_tan;
		}
		else if (sin(r.a)) // Looking DOWN
		{
			r.y = (p_map_pos(cube, 'y') * cube->ts) + (cube->ts / 2);
			r.x = (p.pos.y - r.y) * a_tan + p.pos.x;
			r.yo = cube->ts;
			r.xo = -r.yo * a_tan;
		}
		else if (r.a == 0 || r.a == 2 * PI)
		{
			r.x = p.pos.x;
			r.y = p.pos.y;
			offset = cube->map_height;
		}
		while (offset < cube->map_height)
		{
			r.mx = (int)(r.x + cube->ts / 2) / cube->ts;
			r.my = (int)(r.y) / cube->ts;
			if (r.a > PI && is_in_map(cube, r.mx, r.my) == 1
				&& cube->map[r.my][r.mx] == '1')
			{
				offset = cube->map_height;
			}
			else if (r.a < PI && is_in_map(cube, r.mx, r.my) == 1
				&& cube->map[r.my + 1][r.mx] == '1')
			{
				offset = cube->map_height;
			}
			else
			{
				r.x += r.xo;
				r.y += r.yo;
				offset++;
			}
		}
		r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
				+ (r.y - p.pos.y) * (r.y - p.pos.y));
		cube->h_ray[i] = r;
		r.a += DR;
		if (r.a < 0)
			r.a += 2 * PI;
		if (r.a >= 2 * PI)
		r.a -= 2 * PI;
		i++;
	}
}

void	vertical_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	double		a_tan;
	int			offset;
	int			i;

	i = 0;
	p = cube->p;
	r.a = p.angle - ((FOV / 2) * (DR));
	if (r.a < 0)
		r.a += 2 * PI;
	if (r.a >= 2 * PI)
		r.a -= 2 * PI;
	while (i < FOV)
	{
		offset = 0;
		a_tan = -tan(r.a);
		if (r.a < PI / 2 || r.a > 3 * PI / 2) // looking right
		{
			r.x = p_map_pos(cube, 'x') * cube->ts + (cube->ts / 2);
			r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
			r.xo = -cube->ts;
			r.yo = -r.xo * a_tan;
		}
		else if (r.a > PI / 2 && r.a < 3 * PI / 2) // looking left
		{
			r.x = (p_map_pos(cube, 'x') * cube->ts) - (cube->ts / 2);
			r.y = (p.pos.x - r.x) * a_tan + p.pos.y;
			r.xo = cube->ts;
			r.yo = -r.xo * a_tan;
		}
		else if (r.a == 0 || r.a == PI)
		{
			r.y = p.pos.y;
			r.x = p.pos.x;
			offset = cube->max_line_size;
		}
		while (offset < cube->max_line_size - 1)
		{
			r.my = (int)(r.y + cube->ts / 2) / cube->ts;
			r.mx = (int)(r.x) / cube->ts + 1;
			if (cos(r.a) >= 0 && is_in_map(cube, r.mx, r.my) == 1
				&& cube->map[r.my][r.mx] == '1')
				offset = cube->max_line_size;
			else if (cos(r.a) < 0 && is_in_map(cube, r.mx, r.my) == 1
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
		cube->v_ray[i] = r;
		r.a += DR;
		if (r.a < 0)
			r.a += 2 * PI;
		if (r.a >= 2 * PI)
			r.a -= 2 * PI;
		i++;
	}
}

void	draw_closest_ray(t_cube *cube)
{
	int	i;

	i = 0;
	horizontal_raycast(cube);
	vertical_raycast(cube);
	while (i < FOV)
	{
		dprintf(1, "P ANGLE = %.2f\n", cube->p.angle);
		if (cube->v_ray[i].size <= cube->h_ray[i].size)
			draw_segment(cube, cube->p.pos,
				(t_point){cube->v_ray[i].x, cube->v_ray[i].y}, 65280); // Draw V RAY GREEN
		else
			draw_segment(cube, cube->p.pos,
			 	(t_point){cube->h_ray[i].x, cube->h_ray[i].y}, 65280); // Draw H RAY RED
		i++;
	}
}
