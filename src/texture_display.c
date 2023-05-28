/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/28 05:05:35 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	get_color(t_data img, t_point ratio)
{
	return (*((int *)(img.addr
			+ ((int)ratio.y * img.line_length)
			+ ((int)ratio.x * img.bytes_per_pixel))));
}

t_point	get_ratio(t_cast ray, double height, int ts)
{
	t_point	res;
	int		ray_pos;

	if (ray.type == 'v')
		ray_pos = ray.y;
	else
		ray_pos = ray.x;

	res.x = ray_pos % ts;
	if (res.x < 32)
		res.x += 32;
	else
		res.x -= 32;
	res.y = ts / height;
	return (res);
}

void	draw_texture_column(int x, double height, t_asset ast, t_cube *cube)
{
	t_point	ratio;
	int		pixel_pos;
	int		y;

	if (x < 0 || x > WIN_X || height <= 0)
		return ;
	ratio = get_ratio(cube->ray[x], height, cube->ts);
	y = (WIN_Y - (int)height) / 2;
	pixel_pos = (y * cube->img.line_length)
		+ (x * cube->img.bytes_per_pixel);
	if (y < 0)
	{
		pixel_pos += cube->img.line_length * (-y);
		ratio.y += (cube->ts / height) * (-y);
		y = 0;
	}
	while (y < height + ((WIN_Y - (int)height) / 2) && y < WIN_Y)
	{
		my_custom_pixel_put(&cube->img, pixel_pos, get_color(ast.img, ratio));
		pixel_pos += cube->img.line_length;
		if ((int)(ratio.y + (cube->ts / height)) < cube->ts)
			ratio.y += cube->ts / height;
		y++;
	}
}

int	texture_display(int x, double height, t_cube *cube)
{
	if (cube->ray[x].type == 'h')
	{
		if (cube->ray[x].a >= PI)
			draw_texture_column(x, height, cube->no, cube);
		else
			draw_texture_column(x, height, cube->so, cube);
	}
	else
	{
		if (cube->ray[x].a >= (PI / 2)
			&& cube->ray[x].a < (PI + (PI / 2)))
			draw_texture_column(x, height, cube->we, cube);
		else
			draw_texture_column(x, height, cube->ea, cube);
	}
	return (0);
}
