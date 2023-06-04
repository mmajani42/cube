/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:59:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/04 17:44:22 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

t_point	to_map_coordinates(t_cube *cube, t_point p)
{
	static int	origin = RES - RES / 8 + 1;

	p.x = origin + 1 + (p.x * cube->m_ts);
	p.y = 1 + (p.y * cube->m_ts);
	return (p);
}

void	draw_map_wall(t_cube *cube, t_point	pos)
{
	int			i;
	t_point		m_pos;

	m_pos = to_map_coordinates(cube, pos);
	i = 0;
	while (i < cube->m_ts)
	{
		draw_segment(cube, (t_point){m_pos.x, m_pos.y + i},
			(t_point){m_pos.x + cube->m_ts, m_pos.y + i}, WHITE);
		i++;
	}
}

void	draw_map_background(t_cube *cube)
{
	int			i;
	static int	size = RES / 8;
	static int	origin = RES - RES / 8;

	i = 0;
	while (i < size)
	{
		draw_segment(cube, (t_point){origin, i}, (t_point){RES - 1, i}, GREY);
		i++;
	}
	draw_segment(cube, (t_point){origin, 0}, (t_point){RES, 0}, RED);
	draw_segment(cube, (t_point){origin, size}, (t_point){RES, size}, RED);
	draw_segment(cube, (t_point){origin, 0},
		(t_point){origin, size}, RED);
	draw_segment(cube, (t_point){RES - 1, 0}, (t_point){RES - 1, size}, RED);
}

void	draw_map(t_cube *cube)
{
	int			x;
	int			y;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] == '1')
				draw_map_wall(cube, (t_point){x, y});
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cube *cube)
{
	printf("cube ->m_ts = %.2f\n", cube->m_ts);
	draw_map_background(cube);
	draw_player(cube);
	draw_map(cube);
}
