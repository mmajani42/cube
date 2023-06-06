/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/06 16:09:10 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	horizontal_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	int			i;

	i = 0;
	p = cube->p;
	r.a = p.angle - (cube->fov_radian) / 2;
	r.a = reset_angle(r.a);
	while (i < RES)
	{
		horizontal_ray_maths(cube, &r, &p);
		horizontal_step(cube, &r);
		r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
				+ (r.y - p.pos.y) * (r.y - p.pos.y));
		cube->h_ray[i] = r;
		r.a = -atan((RES / 2 - i + 0.5) / RES / 2) + p.angle;
		r.a = reset_angle(r.a);
		i++;
	}
}

void	vertical_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	int			i;

	i = 0;
	p = cube->p;
	r.a = p.angle - (cube->fov_radian) / 2;
	r.a = reset_angle(r.a);
	while (i < RES)
	{
		vertical_ray_maths(cube, &r, &p);
		vertical_step(cube, &r);
		r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
				+ (r.y - p.pos.y) * (r.y - p.pos.y));
		cube->v_ray[i] = r;
		r.a = -atan((RES / 2 - i + 0.5) / RES / 2) + p.angle;
		r.a = reset_angle(r.a);
		i++;
	}
}

void	draw_closest_ray(t_cube *cube)
{
	int		i;

	i = 0;
	horizontal_raycast(cube);
	vertical_raycast(cube);
	while (i < RES)
	{
		if (cube->v_ray[i].size <= cube->h_ray[i].size)
		{
			cube->ray[i] = cube->v_ray[i];
			cube->ray[i].type = 'v';
		}
		else
		{
			cube->ray[i] = cube->h_ray[i];
			cube->ray[i].type = 'h';
		}
		cube->ray[i].size *= (cos(cube->ray[i].a - cube->p.angle));
		cube->ray[i].size *= 0.5;
		i++;
	}
}
