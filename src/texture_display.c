/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/25 17:22:46 by vimercie         ###   ########lyon.fr   */
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

int	get_color(t_data *img, t_cast ray, int i)
{
	int	res;
	int	color_x;
	int	color_y;

	color_x = 0;
	if (ray.type == 'v')
		color_x = (int)ray.y % 64;
	else if (ray.type == 'h')
		color_x = (int)ray.x % 64;
	color_y = i;
	res = *((int *)(img->addr
				+ (color_y * img->line_length + color_x
					* (img->bits_per_pixel / 8))));
	return (res);
}

void	draw_texture_column(int x, int height, t_data texture, t_cube *cube)
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
	draw_texture_column(x, height, cube->no->img, cube);
	return (0);
}
