/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:18:16 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 16:44:45 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	draw_player(t_cube *cube)
{
	double	x;
	double	y;

	x = cube->p.pos.x;
	y = cube->p.pos.y;
	draw_segment(cube, (t_point){x - (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y - (cube->ts / 8)}, 1000);
	draw_segment(cube, (t_point){x - (cube->ts / 8), y + (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y + (cube->ts / 8)}, 1000);
	draw_segment(cube, (t_point){x - (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x - (cube->ts / 8), y + (cube->ts / 8)}, 1000);
	draw_segment(cube, (t_point){x + (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y + (cube->ts / 8)}, 1000);
}
