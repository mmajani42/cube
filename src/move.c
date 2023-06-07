/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/07 11:46:00 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 4.5

int	get_map_pos(double pos, double ts)
{
	return ((int)round(pos / ts));
}

t_point	get_map_offset(t_point step)
{
	t_point	res;

	if (step.x > 0)
		res.x = 20;
	else
		res.x = -20;
	if (step.y > 0)
		res.y = 20;
	else
		res.y = -20;
	return (res);
}

t_point	combined_movement_vector(t_cube *cube)
{
	t_point	step_walk;
	t_point	step_strafe;
	t_point	final_step;

	step_walk = (t_point){0, 0};
	step_strafe = (t_point){0, 0};
	if (cube->key_w == 1)
		step_walk = (t_point){cos(cube->p.angle), sin(cube->p.angle)};
	else if (cube->key_s == 1)
		step_walk = (t_point){-cos(cube->p.angle), -sin(cube->p.angle)};
	if (cube->key_a == 1)
		step_strafe = (t_point){cos(cube->p.angle - cube->pi_two),
			sin(cube->p.angle - cube->pi_two)};
	else if (cube->key_d == 1)
		step_strafe = (t_point){cos(cube->p.angle + cube->pi_two),
			sin(cube->p.angle + cube->pi_two)};
	final_step = (t_point){(step_walk.x + step_strafe.x) * SPEED,
		(step_walk.y + step_strafe.y) * SPEED};
	return (final_step);
}

t_point	handle_collision(t_cube *cube)
{
	t_point	res;
	t_point	step;
	t_point	offset;

	res = cube->p.pos;
	step = combined_movement_vector(cube);
	offset = get_map_offset(step);
	if ((cube->map[get_map_pos(cube->p.pos.y + offset.x, cube->ts)]
			[get_map_pos(cube->p.pos.x + offset.x + step.x, cube->ts)] != '1')
		&& (cube->map[get_map_pos(cube->p.pos.y - offset.x, cube->ts)]
			[get_map_pos(cube->p.pos.x + offset.x + step.x, cube->ts)] != '1'))
		res.x += step.x;
	if ((cube->map[get_map_pos(cube->p.pos.y + offset.y + step.y, cube->ts)]
			[get_map_pos(cube->p.pos.x + offset.y, cube->ts)] != '1')
		&& (cube->map[get_map_pos(cube->p.pos.y + offset.y + step.y, cube->ts)]
			[get_map_pos(cube->p.pos.x - offset.y, cube->ts)] != '1'))
		res.y += step.y;
	return (res);
}

void	move_player(t_cube *cube)
{
	cube->p.pos = handle_collision(cube);
	if (cube->key_left == 1)
		cube->p.angle -= R_ANGLE * 60;
	else if (cube->key_right == 1)
		cube->p.angle += R_ANGLE * 60;
	cube->p.angle = reset_angle(cube->p.angle);
	if (cube->key_plus == 1 && cube->fov_mult + 0.1 < 2.5)
		cube->fov_mult += 0.1;
	else if (cube->key_minus == 1 && cube->fov_mult - 0.1 > 1)
		cube->fov_mult -= 0.1;
}
