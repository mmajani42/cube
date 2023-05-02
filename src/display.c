/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:20:58 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/02 20:47:27 by mmajani          ###   ########lyon.fr   */
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

void	display_handling(t_cube *cube)
{
	clear_image(cube);
	draw_map(cube);
	draw_player(cube);
	draw_closest_ray(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img.img, 0, 0);
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
