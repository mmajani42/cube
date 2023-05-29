/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/29 18:26:26 by vimercie         ###   ########lyon.fr   */
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
	int	x;

	x = 0;
	while (x <= WIN_X)
	{
		draw_vertical_segment(cube, x, 0, WIN_Y / 2, cube->ceiling.int_hex);
		draw_vertical_segment(cube, x, WIN_Y / 2, WIN_Y, cube->floor.int_hex);
		x++;
	}
	draw_texture(cube);
}

int	gameloop(t_cube *cube)
{
	move_player(cube);
	draw_closest_ray(cube);
	// draw_map(cube);
	// draw_player(cube);
	draw_perspective(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
	return (1);
}
