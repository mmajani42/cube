/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/07 12:54:24 by mmajani          ###   ########lyon.fr   */
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
	while (i < RES)
	{
		r.a = cube->fov_mult * cube->angles[i] + p.angle;
		r.a = reset_angle(r.a);
		horizontal_ray_maths(cube, &r, &p);
		horizontal_step(cube, &r);
		r.size = sqrt(pow(r.x - p.pos.x, 2) + pow(r.y - p.pos.y, 2));
		cube->h_ray[i] = r;
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
	while (i < RES)
	{
		r.a = cube->fov_mult * cube->angles[i] + p.angle;
		r.a = reset_angle(r.a);
		vertical_ray_maths(cube, &r, &p);
		vertical_step(cube, &r);
		r.size = sqrt(pow(r.x - p.pos.x, 2) + pow(r.y - p.pos.y, 2));
		cube->v_ray[i] = r;
		i++;
	}
}

void	display_perspective(t_cube *cube)
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
		draw_perspective(cube, i);
		i++;
	}
}
