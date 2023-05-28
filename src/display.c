/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/28 16:27:05 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	get_color(t_data img, t_point pos)
{
	return (*((int *)(img.addr
			+ ((int)pos.y * img.line_length)
			+ ((int)pos.x * img.bytes_per_pixel))));
}

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
	int		y;

	y = 0;
	while (y <= WIN_Y / 2)
	{
		draw_segment(cube, (t_point){0, y},
			(t_point){WIN_X - 1, y}, WHITE);
		y++;
	}
	while (y <= WIN_Y)
	{
		draw_segment(cube, (t_point){0, y},
			(t_point){WIN_X - 1, y}, GREY);
		y++;
	}
	draw_texture(cube);
}

int	gameloop(t_cube *cube)
{
	//clear_image(cube);
	move_player(cube);
	// cube->p.pos.x = 275;
	// cube->p.pos.y = 64;
	draw_closest_ray(cube);
	draw_map(cube);
	draw_player(cube);
	draw_perspective(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
	return (1);
}
