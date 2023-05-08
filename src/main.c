/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/08 06:20:47 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_mlx(t_cube *cube)
{
	cube->win_x = WIN_X;
	cube->win_y = WIN_Y;
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, cube->win_x,
			cube->win_y, "Hello world!");
	cube->img.img = mlx_new_image(cube->mlx, cube->win_x, cube->win_y);
	cube->img.addr = mlx_get_data_addr(cube->img.img,
			&cube->img.bits_per_pixel, &cube->img.line_length,
			&cube->img.endian);
	cube->img.bits_per_pixel /= 8;
	cube->display_status = 1;
}

int	key_events(int keycode, t_cube *cube)
{
	if (keycode == ESC || keycode == X)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		exit(1);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == Z)
		change_player_vector(cube, keycode);
	return (0);
}

void	print_tab(char **tab)
{	
	int	x;

	x = 0;
	while (tab[x])
	{
		dprintf(1, "%s", tab[x]);
		x++;
	}
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (print_error("This program takes only 1 argument"));
	if (!parsing(av[1], &cube))
		return (0);
	set_tile_size(&cube);
	set_player(&cube);
	init_mlx(&cube);
	mlx_hook(cube.mlx_win, 2, 1L << 0, &key_events, &cube);
	mlx_loop_hook(cube.mlx, &display_handling, &cube);
	mlx_loop(cube.mlx);
	cube_tester(&cube);
	free_cube(&cube);
	return (0);
}
