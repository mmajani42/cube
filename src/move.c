/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/01 19:19:44 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 4
#define R_ANGLE 0.0349066

t_point	rotate_player(t_cube *cube, int key)
{
	t_point	new_vec;
	double	angle;

	angle = R_ANGLE;
	if (key == A)
		angle *= -1;
	new_vec.x = (cube->p.vec.x * cos(angle)) - (cube->p.vec.y * sin(angle));
	new_vec.y = (cube->p.vec.x * sin(angle)) + (cube->p.vec.y * cos(angle));
	return (new_vec);
}

void	change_player_vector(t_cube *cube, int key)
{
	if (key == W)
	{
		cube->p.pos.x += cube->p.vec.x * SPEED;
		cube->p.pos.y += cube->p.vec.y * SPEED;
	}
	if (key == S)
	{
		cube->p.pos.x -= cube->p.vec.x * SPEED;
		cube->p.pos.y -= cube->p.vec.y * SPEED;
	}
	if (key == D || key == A)
	{
		cube->p.vec = rotate_player(cube, key);
		cube->p.angle = atan2(cube->p.vec.y, cube->p.vec.x);
	}
}
