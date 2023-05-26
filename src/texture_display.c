/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/26 15:28:16 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	put_image_to_image(t_data *img, t_cube *cube, int x, int y)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			color = *((int *)(img->addr
						+ (i * img->line_length + j
							* (img->bits_per_pixel / 8))));
			my_mlx_pixel_put(&cube->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	get_color(t_data *img, t_cast ray, int y)
{
	int	res;
	int	x;

	x = 0;
	if (ray.type == 'v')
		x = (int)ray.y % 64;
	else if (ray.type == 'h')
		x = (int)ray.x % 64;
	res = *((int *)(img->addr
				+ (y * img->line_length + x
					* (img->bits_per_pixel / 8))));
	return (res);
}

void	draw_texture(int x, int height, t_data texture, t_cube *cube)
{
	int		color;
	int		y;
	int		i;

	if (x < 0 || x > WIN_X || height <= 0)
		return ;
	i = 0;
	y = (WIN_Y / 2) - (height / 2);
	while (i < height)
	{
		color = get_color(&texture, cube->ray[x], (i * 64) / height);
		my_mlx_pixel_put(&cube->img, x, i + y, color);
		i++;
	}
}

int	texture_display(int x, int height, t_cube *cube)
{
	if (cube->ray[x].type == 'h')
	{
		if (cube->ray[x].a >= PI)
			draw_texture(x, height, cube->no.img, cube);
		else
			draw_texture(x, height, cube->so.img, cube);
	}
	else if (cube->ray[x].type == 'v')
	{
		if (cube->ray[x].a >= (PI / 2)
			&& cube->ray[x].a < (PI + (PI / 2)))
			draw_texture(x, height, cube->we.img, cube);
		else
			draw_texture(x, height, cube->ea.img, cube);
	}
	return (0);
}
