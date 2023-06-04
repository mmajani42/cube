/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 03:01:28 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	check_elements(t_cube *cube)
{
	if (!cube->no.path || !cube->so.path || !cube->ea.path || !cube->we.path
		|| (cube->ceiling.r == -1) || (cube->floor.r == -1))
		return (print_error("Missing elements", NULL));
	return (true);
}

int	set_rgb(t_color *dest, char *line)
{
	char	**rgb;
	char	*color_str;

	if (dest->r != -1 || dest->g != -1 || dest->b != -1)
		return (print_error("Same color key in multiple lines", NULL));
	color_str = get_next_word(line);
	if (!color_str)
		return (0);
	rgb = ft_split(color_str, ',');
	if (!is_rgb(rgb))
	{
		free(color_str);
		free_tab(rgb);
		return (0);
	}
	dest->r = ft_atoi(rgb[0]);
	dest->g = ft_atoi(rgb[1]);
	dest->b = ft_atoi(rgb[2]);
	free(color_str);
	free_tab(rgb);
	set_hex_color(dest);
	dest->int_hex = color_hex_to_int(dest->hex);
	return (1);
}

int	parse_elements(t_cube *cube)
{
	bool	return_val;
	int		i;

	i = 0;
	while (!is_valid_map_line(cube->file[i]) && cube->file[i])
	{
		return_val = 1;
		if (ft_strncmp(cube->file[i], "NO", 2) == 0)
			return_val = init_texture(&cube->no, cube->file[i] + 2, cube->mlx);
		else if (ft_strncmp(cube->file[i], "SO", 2) == 0)
			return_val = init_texture(&cube->so, cube->file[i] + 2, cube->mlx);
		else if (ft_strncmp(cube->file[i], "EA", 2) == 0)
			return_val = init_texture(&cube->ea, cube->file[i] + 2, cube->mlx);
		else if (ft_strncmp(cube->file[i], "WE", 2) == 0)
			return_val = init_texture(&cube->we, cube->file[i] + 2, cube->mlx);
		else if (ft_strncmp(cube->file[i], "F", 1) == 0)
			return_val = set_rgb(&cube->floor, cube->file[i] + 1);
		else if (ft_strncmp(cube->file[i], "C", 1) == 0)
			return_val = set_rgb(&cube->ceiling, cube->file[i] + 1);
		if (!return_val)
			return (0);
		i++;
	}
	return (check_elements(cube));
}
