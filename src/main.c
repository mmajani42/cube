/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/04 02:36:00 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (print_error("This program takes only 1 argument", NULL));
	init_mlx(&cube);
	if (!parsing(av[1], &cube))
		return (0);
	set_player(&cube);
	mlx_hook(cube.mlx_win, 3, 1L << 1, &key_release_events, &cube);
	mlx_hook(cube.mlx_win, 2, 1L << 0, &key_pressed_events, &cube);
	mlx_hook(cube.mlx_win, 17, 1L << 0, &close_cube, &cube);
	mlx_loop_hook(cube.mlx, cube_loop, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
