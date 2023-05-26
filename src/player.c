/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:18:16 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 17:42:33 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	set_player(t_cube *cube)
{
	t_player	p;

	get_player_coordinates(&p, cube->map);
	cube->p.pos.x = ((p.pos.x - 1) * cube->ts) + cube->ts;
	cube->p.pos.y = ((p.pos.y - 1) * cube->ts) + cube->ts;
	cube->p.angle = p.angle;
}

void	draw_orientation(t_cube *cube)
{
	t_point	end;

	end.x = cube->p.pos.x + (cos(cube->p.angle) * 50);
	end.y = cube->p.pos.y + (sin(cube->p.angle) * 50);
	draw_segment(cube, cube->p.pos, end, 0xFFFFF);
}

void	draw_player(t_cube *cube)
{
	double	x;
	double	y;

	x = cube->p.pos.x;
	y = cube->p.pos.y;
	draw_segment(cube, (t_point){x - (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y - (cube->ts / 8)}, 16711680);
	draw_segment(cube, (t_point){x - (cube->ts / 8), y + (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y + (cube->ts / 8)}, 16711680);
	draw_segment(cube, (t_point){x - (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x - (cube->ts / 8), y + (cube->ts / 8)}, 16711680);
	draw_segment(cube, (t_point){x + (cube->ts / 8), y - (cube->ts / 8)},
		(t_point){x + (cube->ts / 8), y + (cube->ts / 8)}, 16711680);
	draw_orientation(cube);
}
