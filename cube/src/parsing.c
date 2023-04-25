/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/25 19:14:22 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

#define TEXTURE 1
#define COLOR 2
#define MAP 3

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

int	parse_line(char *str, t_cube *cube)
{
	
}