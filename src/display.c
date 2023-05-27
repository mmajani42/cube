/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/27 17:21:57 by mmajani          ###   ########lyon.fr   */
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
	double	hh;

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
		h = 100000 / cube->ray[i].size;
		// if (h > 5000)
		// {
		// 	draw_vertical_segment(cube, i, 0, 1080, 1000); 
		// 	i++;
		// 	continue ;
		// }
		// else
		// {
		// 	hh = h / 2;
		// 	draw_vertical_segment(cube, i, HR - (hh), HR + (hh), 1000);

		// }
		texture_display(i, h, cube);
		// draw_segment(cube, (t_point){i, HR - (hh)},
		// 	(t_point){i, HR + (hh)}, 1000);
		i++;
	}
}

int	gameloop(t_cube *cube)
{
	//clear_image(cube);
	move_player(cube);
	// cube->p.pos.x = 275;
	// cube->p.pos.y = 64;
	draw_closest_ray(cube);
	draw_perspective(cube);
	draw_map(cube);
	draw_player(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
	return (1);
}
