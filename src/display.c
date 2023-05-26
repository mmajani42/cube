/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 17:25:40 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	clear_image(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

void	draw_perspective(t_cube *cube)
{
	int		i;
	double	h;

	i = 0;
	while (i <= WIN_Y / 2)
	{
		draw_segment(cube, (t_point){0, i},
			(t_point){WIN_X - 1, i}, WHITE);
		i++;
	}
	while (i <= WIN_Y)
	{
		draw_segment(cube, (t_point){0, i},
			(t_point){WIN_X - 1, i}, GREY);
		i++;
	}
	i = 0;
	while (i < WIN_X)
	{
		h = 100 * (WH / (cube->ray[i].size));
		texture_display(i, (int)h, cube);
		// draw_segment(cube, (t_point){i, HR - (h / 2)},
		// 	(t_point){i, HR + (h / 2)}, 1000);
		// if (i + 1 < WIN_X && cube->ray[i].type != cube->ray[i + 1].type)
		// 	draw_segment(cube, (t_point){i, HR - (h / 2)},
		// 		(t_point){i, HR + (h / 2)}, 0);
		i++;
	}
}

int	gameloop(t_cube *cube)
{
	move_player(cube);
	clear_image(cube);
	draw_closest_ray(cube);
	draw_map(cube);
	draw_player(cube);
	draw_perspective(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
	return (1);
}
