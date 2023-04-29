/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:40:16 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 14:43:23 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	free_cube(t_cube *cube)
{
	free(cube->no);
	free(cube->so);
	free(cube->ea);
	free(cube->we);
	free_tab(cube->map);
}