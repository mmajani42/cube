/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/07 12:32:47 by mmajani          ###   ########lyon.fr   */
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

	y = 0;
	while (y <= WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			my_mlx_pixel_put(&cube->img, x, y, 0);
			x++;
		}
		y++;
	}
}

void	draw_perspective(t_cube *cube)
{
	int			x;
	static int	win2 = WIN_Y / 2;

	x = 0;
	while (x < WIN_X)
	{
		draw_vertical_segment(cube, x, (t_point){0, win2},
			cube->ceiling.int_hex);
		draw_vertical_segment(cube, x, (t_point){win2, WIN_Y},
			cube->floor.int_hex);
		x++;
	}
	draw_wall_texture(cube);
}

int	cube_loop(t_cube *cube)
{
	move_player(cube);
	draw_closest_ray(cube);
	draw_perspective(cube);
	draw_minimap(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
	return (1);
}
