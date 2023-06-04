/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:40:16 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 02:43:22 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_cube(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->no.img.img);
	mlx_destroy_image(cube->mlx, cube->so.img.img);
	mlx_destroy_image(cube->mlx, cube->ea.img.img);
	mlx_destroy_image(cube->mlx, cube->we.img.img);
	mlx_destroy_image(cube->mlx, cube->img.img);
	free(cube->no.path);
	free(cube->so.path);
	free(cube->ea.path);
	free(cube->we.path);
	free(cube->ceiling.hex);
	free(cube->floor.hex);
	free_tab(cube->map);
	free_tab(cube->file);
}

int	close_cube(t_cube *cube)
{
	free_cube(cube);
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_display(cube->mlx);
	exit(1);
}
