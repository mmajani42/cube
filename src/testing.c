/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:24:22 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/26 15:32:01 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	cube_tester(t_cube *cube)
{
	int	i;

	i = 0;
	printf("no = |%s|\n", cube->no.path);
	printf("so = |%s|\n", cube->so.path);
	printf("ea = |%s|\n", cube->ea.path);
	printf("we = |%s|\n", cube->we.path);
	printf("floor = %d,%d,%d\n",
		cube->floor.r, cube->floor.g, cube->floor.b);
	printf("ceiling = %d,%d,%d\n",
		cube->ceiling.r, cube->ceiling.g, cube->ceiling.b);
	printf("\n");
	printf("map_width = %d\n", cube->map_width);
	printf("\n");
	printf("map = \n");
	while (cube->map[i])
	{
		printf("|%s|\n", cube->map[i]);
		i++;
	}
}
