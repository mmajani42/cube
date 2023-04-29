/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:18:16 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 18:45:00 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	set_player(t_cube *cube)
{
	t_point	p_pos;

	p_pos = get_player_pos(cube->map);
	dprintf(1, "PLAYER POS X=%.2f\nPLAYER POS Y=%.2f", p_pos.x, p_pos.y);
	cube->p.pos.x = ((p_pos.x - 1) * cube->ts) + cube->ts;
	cube->p.pos.y = ((p_pos.y - 1) * cube->ts) + cube->ts;
}

void	draw_orientation(t_cube *cube)
{
	t_point	end;

	end.x = cube->p.pos.x + (cube->p.vec.x * 100);
	end.y = cube->p.pos.y + (cube->p.vec.y * 100);
	draw_segment(cube, cube->p.pos, end, 65280);
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
