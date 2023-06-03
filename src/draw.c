/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:20 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/03 16:25:04 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	draw_segment(t_cube *cube, t_point a, t_point b, int color)
{
	double	t;
	double	offset;
	t_point	ab;
	t_point	check;

	t = 0;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	offset = 1 / (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
	while (t <= 1)
	{
		check.x = t * ab.x + a.x;
		check.y = t * ab.y + a.y;
		my_mlx_pixel_put(&cube->img, round(check.x), round(check.y), color);
		t += offset;
	}
}

void	draw_square(t_cube *cube, double x, double y)
{
	draw_segment(cube, (t_point){x - (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y - (cube->ts / 2)}, 16777215);
	draw_segment(cube, (t_point){x - (cube->ts / 2), y + (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y + (cube->ts / 2)}, 16777215);
	draw_segment(cube, (t_point){x - (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x - (cube->ts / 2), y + (cube->ts / 2)}, 16777215);
	draw_segment(cube, (t_point){x + (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y + (cube->ts / 2)}, 16777215);
}

void	draw_dot(t_cube *cube, double x, double y)
{
	draw_segment(cube, (t_point){x - (cube->ts / 20), y - (cube->ts / 20)},
		(t_point){x + (cube->ts / 20), y - (cube->ts / 20)}, 16777215);
	draw_segment(cube, (t_point){x - (cube->ts / 20), y + (cube->ts / 20)},
		(t_point){x + (cube->ts / 20), y + (cube->ts / 20)}, 16777215);
	draw_segment(cube, (t_point){x - (cube->ts / 20), y - (cube->ts / 20)},
		(t_point){x - (cube->ts / 20), y + (cube->ts / 20)}, 16777215);
	draw_segment(cube, (t_point){x + (cube->ts / 20), y - (cube->ts / 20)},
		(t_point){x + (cube->ts / 20), y + (cube->ts / 20)}, 16777215);
}

void	draw_vertical_segment(t_cube *cube, int x, t_point pos, int color)
{
	int	delta;
	int	height;
	int	y;
	int	i;

	delta = 1;
	height = pos.y - pos.x;
	if (pos.x > pos.y)
	{
		delta = -1;
		height = pos.x - pos.y;
	}
	y = pos.x;
	i = 0;
	while (i <= height)
	{
		my_mlx_pixel_put(&cube->img, x, y, color);
		y += delta;
		i++;
	}
}

void	draw_map(t_cube *cube)
{
	int	y;
	int	x;

	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] == '1')
				draw_square(cube, (x * cube->ts), (y * cube->ts));
			x++;
		}
		y++;
	}
}
