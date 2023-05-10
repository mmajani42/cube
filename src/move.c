/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/10 22:14:08 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 10

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
		cube->p.angle -= R_ANGLE * 100;
	}
	if (key == D)
		cube->p.angle += R_ANGLE * 100;
	if (cube->p.angle >= 2 * PI)
		cube->p.angle -= 2 * PI;
	else if (cube->p.angle < 0)
		cube->p.angle += 2 * PI;
}
