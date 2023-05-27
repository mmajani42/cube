/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/27 08:32:27 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 0.1

void	move_player(t_cube *cube)
{	
	if (cube->key_w == 1)
	{
		cube->p.pos.x += (cos(cube->p.angle)) * SPEED * cube->ts;
		cube->p.pos.y += (sin(cube->p.angle)) * SPEED * cube->ts;
	}
	else if (cube->key_s == 1)
	{
		cube->p.pos.x -= (cos(cube->p.angle)) * SPEED * cube->ts;
		cube->p.pos.y -= (sin(cube->p.angle)) * SPEED * cube->ts;
	}
	if (cube->key_a == 1)
		cube->p.angle -= R_ANGLE * 70;
	else if (cube->key_d == 1)
		cube->p.angle += R_ANGLE * 70;
	if (cube->p.angle >= 2 * PI)
		cube->p.angle -= 2 * PI;
	else if (cube->p.angle < 0)
		cube->p.angle += 2 * PI;
}
