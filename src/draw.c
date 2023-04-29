/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:20 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 14:50:14 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_X || y >= WIN_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel));
	*(unsigned int *)dst = color;
}

void	clear_image(t_cube *cube)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y <= WIN_Y)
	{
		while (x < WIN_X)
		{
			my_mlx_pixel_put(&cube->img, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}

// void	safe_pixel_put(t_point *point, t_cube *cube, int color)
// {
// 	if (is_drawable(point->x + cube->offset_x, point->y + cube->offset_y))
// 	{
// 		my_mlx_pixel_put(&fdf->img, point->x + fdf->offset_x,
// 			point->y + fdf->offset_y, color);
// 	}
// }

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
		my_mlx_pixel_put(&cube->img, check.x, check.y, color);
		t += offset;
	}
}

void	display_axis(t_cube *cube)
{
	t_point	x;
	t_point	y;

	x.x = 0;
	x.y = WIN_Y / 2;
	y.x = WIN_X / 2;
	y.y = 0;
	while (x.x++ < WIN_X)
		my_mlx_pixel_put(&cube->img, x.x, x.y, 1000);
	while (y.y++ < WIN_Y)
		my_mlx_pixel_put(&cube->img, y.x, y.y, 1000);
}

void	draw_square(t_cube *cube, double x, double y)
{
	draw_segment(cube, (t_point){x - (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y - (cube->ts / 2)}, 1000);
	draw_segment(cube, (t_point){x - (cube->ts / 2), y + (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y + (cube->ts / 2)}, 1000);
	draw_segment(cube, (t_point){x - (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x - (cube->ts / 2), y + (cube->ts / 2)}, 1000);
	draw_segment(cube, (t_point){x + (cube->ts / 2), y - (cube->ts / 2)},
		(t_point){x + (cube->ts / 2), y + (cube->ts / 2)}, 1000);
}
