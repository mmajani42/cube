/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:18:16 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 17:12:15 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	set_player(t_cube *cube)
{
	t_point	p_pos;

	p_pos = get_player_pos(cube->map);
	cube->p.pos.x = (p_pos.x * cube->ts) - cube->ts / 2;
	cube->p.pos.y = (p_pos.y * cube->ts) - cube->ts / 2;
}

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
