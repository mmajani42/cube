/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 17:47:25 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	set_texture(t_asset *asset, void *mlx)
{
	asset->img.img = mlx_xpm_file_to_image(mlx, asset->path,
			&asset->width, &asset->height);
	asset->img.addr = mlx_get_data_addr(asset->img.img,
			&asset->img.bits_per_pixel,
			&asset->img.line_length,
			&asset->img.endian);
}

void	init_assets(t_cube *cube)
{
	set_texture(&cube->no, cube->mlx);
	set_texture(&cube->so, cube->mlx);
	set_texture(&cube->we, cube->mlx);
	set_texture(&cube->ea, cube->mlx);
}

void	init_mlx(t_cube *cube)
{
	cube->win_x = WIN_X;
	cube->win_y = WIN_Y;
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, cube->win_x,
			cube->win_y, "Cub3d");
	cube->img.img = mlx_new_image(cube->mlx, cube->win_x, cube->win_y);
	cube->img.addr = mlx_get_data_addr(cube->img.img,
			&cube->img.bits_per_pixel, &cube->img.line_length,
			&cube->img.endian);
	cube->img.bits_per_pixel /= 8;
	cube->display_status = 1;
	init_assets(cube);
}

void	init_cube(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
	cube->no.path = NULL;
	cube->so.path = NULL;
	cube->we.path = NULL;
	cube->ea.path = NULL;
	cube->floor.r = -1;
	cube->floor.g = -1;
	cube->floor.b = -1;
	cube->ceiling.r = -1;
	cube->ceiling.g = -1;
	cube->ceiling.b = -1;
	cube->map_height = 0;
	cube->map_width = 0;
	cube->off_x = 0;
	cube->off_y = 0;
	cube->fov_radian = FOV * PI / 180;
	cube->ts = 64;
}
