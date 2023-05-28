/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/28 02:06:42 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

t_point	get_ratio(t_cast ray, double wall_height, int ts)
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
	res.y = ts / wall_height;
	return (res);
}

int	get_color(t_data img, int x, int y)
{
	return (*((int *)(img.addr
			+ (y * img.line_length)
			+ (x * img.bytes_per_pixel))));
}

void	draw_texture(int x, double wall_height, t_asset ast, t_cube *cube)
{
	int		wall_top;
	t_point	ratio;
	double	ratio_y;
	int		pixel_pos;
	int		i;

	if (x < 0 || x > WIN_X || wall_height <= 0)
		return ;
	wall_top = (WIN_Y / 2) - ((int)wall_height / 2);
	i = wall_top;
	ratio = get_ratio(cube->ray[x], wall_height, cube->ts);
	ratio_y = ratio.y;
	pixel_pos = (wall_top * cube->img.line_length)
		+ (x * cube->img.bytes_per_pixel);
	if (i < 0)
	{
		pixel_pos += cube->img.line_length * (-i);
		ratio.y += ratio_y * (-i);
		i = 0;
	}
	while (i < wall_height + wall_top && i < WIN_Y)
	{
		if (i >= 0 && i <= WIN_Y)
		{
			my_custom_pixel_put(&cube->img, pixel_pos,
				get_color(ast.img, ratio.x, ratio.y));
		}
		pixel_pos += cube->img.line_length;
		if ((int)(ratio.y + ratio_y) < cube->ts)
			ratio.y += ratio_y;
		i++;
	}
}

int	texture_display(int x, double height, t_cube *cube)
{
	if (cube->ray[x].type == 'h')
	{
		if (cube->ray[x].a >= PI)
			draw_texture(x, height, cube->no, cube);
		else
			draw_texture(x, height, cube->so, cube);
	}
	else
	{
		if (cube->ray[x].a >= (PI / 2)
			&& cube->ray[x].a < (PI + (PI / 2)))
			draw_texture(x, height, cube->we, cube);
		else
			draw_texture(x, height, cube->ea, cube);
	}
	return (0);
}
