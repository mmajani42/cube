/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/10 12:06:19 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 10
#define R_ANGLE 0.0349066

t_point	rotate_player(t_cube *cube, int key)
{
	t_point	new_vec;
	double	angle;

	angle = R_ANGLE;
	if (key == A || key == Q)
	{
		new_vec.x = (cube->p.vec.x * cos(-angle)) - (cube->p.vec.y * sin(-angle));
		new_vec.y = (cube->p.vec.x * sin(-angle)) + (cube->p.vec.y * cos(-angle));
		return (new_vec);
	}
	new_vec.x = (cube->p.vec.x * cos(angle)) - (cube->p.vec.y * sin(angle));
	new_vec.y = (cube->p.vec.x * sin(angle)) + (cube->p.vec.y * cos(angle));
	return (new_vec);
}

void	change_player_vector(t_cube *cube, int key)
{
	if (key == W || key == Z)
	{
		cube->p.pos.x += (cos(cube->p.angle)) * SPEED;
		cube->p.pos.y += (sin(cube->p.angle)) * SPEED;
	}
	if (key == S)
	{
		cube->p.pos.x -= (cos(cube->p.angle)) * SPEED;
		cube->p.pos.y -= (sin(cube->p.angle)) * SPEED;
	}
	if (key == A || key == Q)
	{
	//	cube->p.vec = rotate_player(cube, key);
		cube->p.angle -= R_ANGLE * 2;
	}
	if (key == D)
		cube->p.angle += R_ANGLE * 2;
	if (cube->p.angle >= 2 * PI)
		cube->p.angle -= 2 * PI;
	else if (cube->p.angle < 0)
		cube->p.angle += 2 * PI;
}
