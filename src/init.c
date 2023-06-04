/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/04 03:10:44 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	init_texture(t_asset *ast, char *line, void *mlx)
{
	if (ast->path != NULL)
		return (print_error("Same texture key in multiple lines", NULL));
	ast->path = get_texture_path(line);
	if (!ast->path)
		return (print_error("No texture path", NULL));
	ast->img.img = mlx_xpm_file_to_image(mlx, ast->path,
			&ast->width, &ast->height);
	if (!ast->img.img)
		return (print_error("Invalid .xpm file", ast->path));
	ast->img.addr = mlx_get_data_addr(ast->img.img,
			&ast->img.bits_per_pixel,
			&ast->img.line_length,
			&ast->img.endian);
	if (!ast->img.addr)
		return (print_error("Can't get data adress", ast->path));
	ast->img.bytes_per_pixel = ast->img.bits_per_pixel / 8;
	return (1);
}

void	init_cube(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
	cube->no.path = NULL;
	cube->so.path = NULL;
	cube->we.path = NULL;
	cube->ea.path = NULL;
	cube->floor.hex = NULL;
	cube->ceiling.hex = NULL;
	cube->floor.r = -1;
	cube->floor.g = -1;
	cube->floor.b = -1;
	cube->ceiling.r = -1;
	cube->ceiling.g = -1;
	cube->ceiling.b = -1;
	cube->map_height = 0;
	cube->map_width = 0;
	cube->fov_radian = FOV * PI / 180;
	cube->ts = 64;
	cube->key_w = 0;
	cube->key_a = 0;
	cube->key_s = 0;
	cube->key_d = 0;
	cube->key_left = 0;
	cube->key_right = 0;
}

void	init_mlx(t_cube *cube)
{
	cube->win_x = WIN_X;
	cube->win_y = WIN_Y;
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx,
			cube->win_x, cube->win_y, "cub3D");
	cube->img.img = mlx_new_image(cube->mlx, cube->win_x, cube->win_y);
	cube->img.addr = mlx_get_data_addr(cube->img.img,
			&cube->img.bits_per_pixel,
			&cube->img.line_length,
			&cube->img.endian);
	cube->img.bytes_per_pixel = cube->img.bits_per_pixel / 8;
	cube->display_status = 1;
}
