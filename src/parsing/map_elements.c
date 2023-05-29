/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/29 18:09:39 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	set_hex_color(t_color *color)
{
	char	*hex_color;

	color->hex = ft_calloc(9, sizeof(char));
	ft_strlcpy(color->hex, "0x", 3);
	hex_color = color_int_to_hex(color->r);
	ft_strlcpy(color->hex + 2, hex_color, 3);
	free(hex_color);
	hex_color = color_int_to_hex(color->g);
	ft_strlcpy(color->hex + 4, hex_color, 3);
	free(hex_color);
	hex_color = color_int_to_hex(color->b);
	ft_strlcpy(color->hex + 6, hex_color, 3);
	free(hex_color);
}

int	set_color(t_color *dest, char *line)
{
	char	**rgb;
	char	*color_str;

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

int	set_texture_path(char **dest, char *line)
{
	*dest = get_next_word(line);
	if (!check_file_extension(*dest, ".xpm"))
	{
		free(*dest);
		*dest = NULL;
		return (print_error("Invalid asset format"));
	}
	if (access(*dest, R_OK) == -1)
	{
		perror(*dest);
		free(*dest);
		*dest = NULL;
		return (0);
	}
	return (1);
}

int	parse_elements(t_cube *cube)
{
	int	n_assets;
	int	i;

	i = 0;
	n_assets = 0;
	while (n_assets < 6 && !is_valid_map_line(cube->file[i]) && cube->file[i])
	{
		if (ft_strncmp(cube->file[i], "NO", 2) == 0 && !cube->no.path)
			n_assets += set_texture_path(&cube->no.path, cube->file[i] + 2);
		if (ft_strncmp(cube->file[i], "SO", 2) == 0 && !cube->so.path)
			n_assets += set_texture_path(&cube->so.path, cube->file[i] + 2);
		if (ft_strncmp(cube->file[i], "EA", 2) == 0 && !cube->ea.path)
			n_assets += set_texture_path(&cube->ea.path, cube->file[i] + 2);
		if (ft_strncmp(cube->file[i], "WE", 2) == 0 && !cube->we.path)
			n_assets += set_texture_path(&cube->we.path, cube->file[i] + 2);
		if (ft_strncmp(cube->file[i], "F", 1) == 0 && cube->floor.r == -1)
			n_assets += set_color(&cube->floor, cube->file[i] + 1);
		if (ft_strncmp(cube->file[i], "C", 1) == 0 && cube->ceiling.r == -1)
			n_assets += set_color(&cube->ceiling, cube->file[i] + 1);
		i++;
	}
	if (n_assets < 6)
		return (print_error("Invalid map elements"));
	return (1);
}
