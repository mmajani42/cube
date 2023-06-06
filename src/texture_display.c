/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:56 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/06 17:06:22 by mmajani          ###   ########lyon.fr   */
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

void	draw_texture_column(t_point pos, int h, t_asset ast, t_cube *cube)
{
	int		wall_top;
	int		win_pos;
	t_point	ratio;
	double	ratio_step;

	if (pos.x < 0 || pos.x > WIN_X)
		return ;
	wall_top = (WIN_Y - (int)h) / 2;
	win_pos = pos.x * cube->img.bytes_per_pixel;
	ratio.x = get_ratio_x(pos.x, cube);
	ratio.y = cube->ts / h;
	ratio_step = ratio.y;
	pos.y = set_loop_vars(wall_top, &win_pos, &ratio.y, cube);
	while (pos.y < h + wall_top && pos.y < WIN_Y)
	{
		if (ratio.y >= cube->ts)
			ratio.y--;
		my_custom_pixel_put(&cube->img, win_pos, get_color(ast.img, ratio));
		win_pos += cube->img.line_length;
		ratio.y += ratio_step;
		pos.y++;
	}
}

void	draw_texture(t_cube *cube)
{
	t_point	pos;
	int		height;

	pos.x = 0;
	while (pos.x < WIN_X)
	{
		height = (cube->ts * WIN_X) / cube->ray[(int)pos.x].size * 2;
		draw_texture_column(pos, height, get_texture(pos.x, cube), cube);
		pos.x++;
	}
}
