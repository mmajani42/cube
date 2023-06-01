/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/01 15:41:58 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 0.07

int	get_map_pos(double pos, double ts)
{
	return ((int)round(pos / ts));
}

t_point	get_map_offset(t_cube *cube)
{
	t_point	res;
	double	offset;

	offset = 20;
	res = (t_point){0, 0};
	if (cube->p.angle < PI)
		res.y = offset;
	else
		res.y = -offset;
	if (cube->p.angle > PI / 2 && cube->p.angle <= PI + (PI / 2))
		res.x = -offset;
	else
		res.x = offset;
	if (cube->key_s == 1)
	{
		res.x = -res.x;
		res.y = -res.y;
	}
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
		step_walk = (t_point){cos(cube->p.angle) * cube->ts * SPEED,
			sin(cube->p.angle) * cube->ts * SPEED};
	else if (cube->key_s == 1)
		step_walk = (t_point){cos(cube->p.angle) * cube->ts * SPEED * -1,
			sin(cube->p.angle) * cube->ts * SPEED * -1};
	if (cube->key_left == 1)
		step_strafe = (t_point){cos(cube->p.angle - PI / 2),
			sin(cube->p.angle - PI / 2)};
	else if (cube->key_right == 1)
		step_strafe = (t_point){cos(cube->p.angle + PI / 2),
			sin(cube->p.angle + PI / 2)};
	final_step = (t_point){step_walk.x + step_strafe.x,
		step_walk.y + step_strafe.y};
	return (final_step);
}

t_point	handle_collision(t_cube *cube)
{
	t_point	res;
	t_point	step;
	t_point	offset;

	res = cube->p.pos;
	step = combined_movement_vector(cube);
	offset = get_map_offset(cube);
	if (cube->map[get_map_pos(cube->p.pos.y, cube->ts)]
		[get_map_pos(cube->p.pos.x + offset.x + step.x, cube->ts)] != '1')
		res.x += step.x;
	if (cube->map[get_map_pos(cube->p.pos.y + offset.y + step.y, cube->ts)]
		[get_map_pos(cube->p.pos.x, cube->ts)] != '1')
		res.y += step.y;
	return (res);
}

void	move_player(t_cube *cube)
{
	cube->p.pos = handle_collision(cube);
	if (cube->key_a == 1)
		cube->p.angle -= R_ANGLE * 70;
	else if (cube->key_d == 1)
		cube->p.angle += R_ANGLE * 70;
	cube->p.angle = reset_angle(cube->p.angle);
}
