/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 16:40:11 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	is_rgb(char **tab)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (false);
			j++;
		}
		n = ft_atoi(tab[i]);
		if (n < 0 || n > 255)
			return (false);
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

bool	is_wall(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] == ' ' || line[i] == '1')
		i++;
	if (line[i] == '\n' && i >= 2)
		return (true);
	return (false);
}

bool	is_valid_map_line(char *line)
{
	if (ft_is_string_blank(line))
		return (false);
	while (line[0] != '\n' && line[0])
	{
		if (line[0] != '0'
			&& line[0] != '1'
			&& line[0] != 'N'
			&& line[0] != 'S'
			&& line[0] != 'E'
			&& line[0] != 'W'
			&& line[0] != ' ')
			return (false);
		line++;
	}
	return (true);
}
