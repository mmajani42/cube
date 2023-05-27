/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/27 12:39:10 by vimercie         ###   ########lyon.fr   */
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
	asset->img.bytes_per_pixel = asset->img.bits_per_pixel / 8;
}

void	init_assets(t_cube *cube)
{
	set_texture(&cube->no, cube->mlx);
	set_texture(&cube->so, cube->mlx);
	set_texture(&cube->we, cube->mlx);
	set_texture(&cube->ea, cube->mlx);
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
	cube->key_w = 0;
	cube->key_a = 0;
	cube->key_s = 0;
	cube->key_d = 0;
	cube->key_left = 0;
	cube->key_right = 0;
}
