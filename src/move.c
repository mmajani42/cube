/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:24:31 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 18:47:01 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define SPEED 10

void	change_player_vector(t_cube *cube, int key)
{
	cube->p.vec.x = 0;
	cube->p.vec.y = -1;
	if (key == W)
	{
		cube->p.pos.x += cube->p.vec.x;
		cube->p.pos.y += cube->p.vec.y;
	}
	if (key == S)
	{
		cube->p.pos.x -= cube->p.vec.x;
		cube->p.pos.y -= cube->p.vec.y;
	}
}
