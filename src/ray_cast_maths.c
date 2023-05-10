/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:51:54 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/10 21:28:21 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	horizontal_ray_maths(t_cube *cube, t_cast *r, t_player *p)
{
	r->dof = 0;
	if (r->a == 0 || r->a == 2 * PI)
	{
		r->x = p->pos.x;
		r->y = p->pos.y;
		r->dof = cube->map_height;
	}
	else if (sin(r->a) < 0) // Looking UP
	{
		r->a_tan = -1 / tan(r->a);
		r->y = p_map_pos(cube, 'y') * cube->ts - (cube->ts / 2);
		r->x = (p->pos.y - r->y) * r->a_tan + p->pos.x;
		r->yo = -cube->ts;
		r->xo = -r->yo * r->a_tan;
	}
	else //(sin(r->a)) // Looking DOWN
	{
		r->a_tan = -1 / tan(r->a);
		r->y = (p_map_pos(cube, 'y') * cube->ts) + (cube->ts / 2);
		r->x = (p->pos.y - r->y) * r->a_tan + p->pos.x;
		r->yo = cube->ts;
		r->xo = -r->yo * r->a_tan;
	}
}

void	vertical_ray_maths(t_cube *cube, t_cast *r, t_player *p)
{
	r->dof = 0;
	if (r->a == 0 || r->a == PI)
	{
		r->y = p->pos.y;
		r->x = p->pos.x;
		r->dof = cube->max_line_size;
	}
	else if (r->a < PI / 2 || r->a > 3 * PI / 2) // looking right
	{
		r->a_tan = -tan(r->a);
		r->x = p_map_pos(cube, 'x') * cube->ts + (cube->ts / 2);
		r->y = (p->pos.x - r->x) * r->a_tan + p->pos.y;
		r->xo = -cube->ts;
		r->yo = -r->xo * r->a_tan;
	}
	else //(r->a > PI / 2 && r->a < 3 * PI / 2) // looking left
	{
		r->a_tan = -tan(r->a);
		r->x = (p_map_pos(cube, 'x') * cube->ts) - (cube->ts / 2);
		r->y = (p->pos.x - r->x) * r->a_tan + p->pos.y;
		r->xo = cube->ts;
		r->yo = -r->xo * r->a_tan;
	}
}

void	vertical_step(t_cube *cube, t_cast *r)
{
	while (r->dof < cube->max_line_size - 1)
	{
		r->my = (int)(r->y + cube->ts / 2) / cube->ts;
		r->mx = (int)(r->x) / cube->ts + 1;
		if (cos(r->a) >= 0 && is_in_map(cube, r->mx, r->my) == 1
			&& cube->map[r->my][r->mx] == '1')
			r->dof = cube->max_line_size;
		else if (cos(r->a) < 0 && is_in_map(cube, r->mx - 1, r->my) == 1
			&& cube->map[r->my][r->mx - 1] == '1')
			r->dof = cube->max_line_size;
		else
		{
			r->y -= r->yo;
			r->x -= r->xo;
			r->dof++;
		}
	}
}

void	horizontal_step(t_cube *cube, t_cast *r)
{
	while (r->dof < cube->map_height - 1)
	{
		r->mx = (int)(r->x + cube->ts / 2) / cube->ts;
		r->my = (int)(r->y) / cube->ts;
		if (r->a > PI && is_in_map(cube, r->mx, r->my) == 1
			&& cube->map[r->my][r->mx] == '1')
			r->dof = cube->map_height;
		else if (r->a < PI && is_in_map(cube, r->mx, r->my + 1) == 1
			&& cube->map[r->my + 1][r->mx] == '1')
			r->dof = cube->map_height;
		else
		{
			r->x += r->xo;
			r->y += r->yo;
			r->dof++;
		}	
	}
}
