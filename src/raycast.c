/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:46:36 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/10 18:15:29 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	horizontal_raycast(t_cube *cube)
{
	t_cast		r;
	t_player	p;
	int			i;

	i = 0;
	p = cube->p;
	r.a = p.angle - ((FOV / 2) * DR);
	r.a = reset_angle(r.a);
	while (i < FOV)
	{
		horizontal_ray_maths(cube, &r, &p);
		horizontal_step(cube, &r);
		r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
				+ (r.y - p.pos.y) * (r.y - p.pos.y));
		cube->h_ray[i] = r;
		r.a += DR;
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
	r.a = p.angle - ((FOV / 2) * (DR));
	r.a = reset_angle(r.a);
	while (i < FOV)
	{
		vertical_ray_maths(cube, &r, &p);
		vertical_step(cube, &r);
		r.size = sqrt(((r.x - p.pos.x) * (r.x - p.pos.x))
				+ (r.y - p.pos.y) * (r.y - p.pos.y));
		cube->v_ray[i] = r;
		r.a += DR;
		r.a = reset_angle(r.a);
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
		if (cube->v_ray[i].size <= cube->h_ray[i].size)
			cube->ray[i] = cube->v_ray[i];
		else
			cube->ray[i] = cube->h_ray[i];
		draw_segment(cube, cube->p.pos,
			(t_point){cube->ray[i].x, cube->ray[i].y}, 65280);
		i++;
	}
}
