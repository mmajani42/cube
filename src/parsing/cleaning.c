/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:40:16 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 03:24:46 by vimercie         ###   ########lyon.fr   */
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

void	free_asset(t_asset *ast, void *mlx)
{
	if (!ast->path)
		return ;
	free(ast->path);
	mlx_destroy_image(mlx, ast->img.img);
}

void	free_cube(t_cube *cube)
{
	free_asset(&cube->no, cube->mlx);
	free_asset(&cube->so, cube->mlx);
	free_asset(&cube->ea, cube->mlx);
	free_asset(&cube->we, cube->mlx);
	free(cube->ceiling.hex);
	free(cube->floor.hex);
	free_tab(cube->map);
	free_tab(cube->file);
}

int	close_cube(t_cube *cube)
{
	free_cube(cube);
	mlx_destroy_image(cube->mlx, cube->img.img);
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	mlx_destroy_display(cube->mlx);
	exit(1);
}
