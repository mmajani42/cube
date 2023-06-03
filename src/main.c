/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/03 16:43:07 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	close_cube(t_cube *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	exit(1);
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (print_error("This program takes only 1 argument"));
	if (!parsing(av[1], &cube))
		return (0);
	set_player(&cube);
	init_mlx(&cube);
	mlx_hook(cube.mlx_win, 3, 1L << 1, &key_release_events, &cube);
	mlx_hook(cube.mlx_win, 2, 1L << 0, &key_pressed_events, &cube);
	mlx_hook(cube.mlx_win, 17, 1L << 0, &close_cube, &cube);
	mlx_loop_hook(cube.mlx, gameloop, &cube);
	mlx_loop(cube.mlx);
	cube_tester(&cube);
	free_cube(&cube);
	return (0);
}
