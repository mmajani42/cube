/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:18:16 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/06 08:56:33 by mmajani          ###   ########lyon.fr   */
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
	cube->key_a = 0;
	cube->key_s = 0;
	cube->key_d = 0;
	cube->key_w = 0;
	cube->key_left = 0;
	cube->key_right = 0;
}

void	draw_orientation(t_cube *cube, t_point	pos)
{
	t_point	end;

	pos.x += cube->m_ts / 8;
	pos.y += cube->m_ts / 8;
	end.x = pos.x + (cos(cube->p.angle) * cube->m_ts);
	end.y = pos.y + (sin(cube->p.angle) * cube->m_ts);
	draw_segment(cube, pos, end, 0xFFFFF);
}

void	draw_player(t_cube *cube)
{
	int			i;
	t_point		m_pos;
	double		ts;

	ts = cube->m_ts / 4;
	m_pos = cube->p.pos;
	m_pos.x = (m_pos.x / 64);
	m_pos.y = (m_pos.y / 64);
	m_pos = to_map_coordinates(cube, m_pos);
	m_pos.x += ts + ts / 2;
	m_pos.y += ts + ts / 2;
	m_pos.x += cube->m_off.x;
	m_pos.y += cube->m_off.y;
	i = 0;
	draw_orientation(cube, m_pos);
	while (i < ts)
	{
		draw_segment(cube, (t_point){m_pos.x, m_pos.y + i},
			(t_point){m_pos.x + ts, m_pos.y + i}, RED);
		i++;
	}
}
