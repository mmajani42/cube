/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/07 12:19:11 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

t_asset	get_texture(int x, t_cube *cube)
{
	if (cube->ray[x].type == 'h')
	{
		if (cube->ray[x].a >= PI)
			return (cube->no);
		else
			return (cube->so);
	}
	else
	{
		if (cube->ray[x].a >= (PI / 2)
			&& cube->ray[x].a < (PI + (PI / 2)))
			return (cube->we);
		else
			return (cube->ea);
	}
}

double	get_ratio_x(int x, t_cube *cube)
{
	double	res;
	int		ray_pos;

	if (cube->ray[x].type == 'v')
		ray_pos = cube->ray[x].y;
	else
		ray_pos = cube->ray[x].x;
	res = ray_pos % (int)cube->ts;
	if (res < 32)
		res += 32;
	else
		res -= 32;
	return (res);
}

int	set_loop_vars(int start, int *win_pos, double *ratio_y, t_cube *cube)
{
	double	ratio_y_tmp;

	ratio_y_tmp = *ratio_y;
	if (start >= 0)
	{
		*win_pos += start * cube->img.line_length;
		return (start);
	}
	*ratio_y -= start * ratio_y_tmp;
	return (0);
}

void	draw_texture_column(int x, double height, t_asset ast, t_cube *cube)
{
	int		win_pos;
	t_point	ratio;
	double	ratio_y;
	double	wall_top;
	int		y;

	if (x < 0 || x > WIN_X)
		return ;
	wall_top = (WIN_Y - height) / 2;
	win_pos = x * cube->img.bytes_per_pixel;
	ratio.x = get_ratio_x(x, cube);
	ratio.y = cube->ts / height;
	ratio_y = ratio.y;
	y = set_loop_vars((int)wall_top, &win_pos, &ratio.y, cube);
	while (y < (int)round(height + wall_top) && y < WIN_Y)
	{
		my_custom_pixel_put(&cube->img, win_pos, get_color(ast.img, ratio));
		win_pos += cube->img.line_length;
		ratio.y = ratio_y * (y - wall_top);
		y++;
	}
}

void	draw_wall_texture(t_cube *cube)
{
	int		x;
	double	height;

	x = 0;
	while (x < WIN_X)
	{
		height = (((cube->ts * WIN_X / cube->fov_radian) * PI)
				/ cube->ray[x].size) / cube->fov_mult;
		draw_texture_column(x, height, get_texture(x, cube), cube);
		x++;
	}
}
