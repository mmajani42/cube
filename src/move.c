/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/01 02:11:56 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 0.07

int	get_map_pos(double pos, double ts)
{
	return ((int)round(pos / ts));
}

t_point	handle_collision(t_cube *cube)
{
	t_point	res;
	double	x_step;
	double	y_step;

	res = cube->p.pos;
	if (!cube->key_w && !cube->key_s)
		return (res);
	x_step = cos(cube->p.angle) * cube->ts * SPEED;
	y_step = sin(cube->p.angle) * cube->ts * SPEED;
	if (cube->key_s == 1)
	{
		x_step = -x_step;
		y_step = -y_step;
	}
	if (cube->map[get_map_pos(cube->p.pos.y, cube->ts)]
		[get_map_pos(cube->p.pos.x + x_step, cube->ts)] != '1')
		res.x += x_step;
	if (cube->map[get_map_pos(cube->p.pos.y + y_step, cube->ts)]
		[get_map_pos(cube->p.pos.x, cube->ts)] != '1')
		res.y += y_step;
	return (res);
}

void	move_player(t_cube *cube)
{
	cube->p.pos = handle_collision(cube);
	if (cube->key_a == 1)
		cube->p.angle -= R_ANGLE * 70;
	else if (cube->key_d == 1)
		cube->p.angle += R_ANGLE * 70;
	if (cube->p.angle >= 2 * PI)
		cube->p.angle -= 2 * PI;
	else if (cube->p.angle < 0)
		cube->p.angle += 2 * PI;
}
