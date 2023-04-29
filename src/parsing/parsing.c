/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 16:42:55 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

#define TEXTURE 1
#define COLOR 2
#define MAP 3

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	parsing_selector(char *s)
{
	if (s[0] == 'N' || s[0] == 'S' || s[0] == 'W' || s[0] == 'E')
		return (TEXTURE);
	else if (s[0] == 'F' || s[0] == 'C')
		return (COLOR);
	else if (s[0] == '1')
		return (MAP);
	return (0);
}

int	parsing(char *filename, t_cube *cube)
{
	char	**file_tab;

	file_tab = file_to_tab(filename);
	parse_elements(file_tab, cube);
	parse_description(file_tab, cube);
	cube_tester(cube);
	free_cube(cube);
	return (1);
}
