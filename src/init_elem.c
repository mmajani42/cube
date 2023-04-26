/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/26 18:02:34 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

char	*get_texture_path(char *line)
{
	char	*res;

	res = ft_strndup(line, ft_strlen(line) - 1);
	while (!ft_is_string_blank(res))
	{
		if (access(res, F_OK) == 0)
			return (res);
		free(res);
		res = ft_strndup(line, ft_strlen(line) - 1);
		line += 1;
	}
	return (NULL);
}

int	parse_elements(char **file, t_cube *cube)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strncmp(file[i], "NO ", 3) == 0 || !cube->no)
			cube->no = get_texture_path(file[i]);
		if (ft_strncmp(file[i], "SO ", 3) == 0 || !cube->so)
			cube->so = get_texture_path(file[i]);
		if (ft_strncmp(file[i], "EA ", 3) == 0 || !cube->ea)
			cube->ea = get_texture_path(file[i]);
		if (ft_strncmp(file[i], "WE ", 3) == 0 || !cube->we)
			cube->we = get_texture_path(file[i]);
		i++;
	}
	printf("cube->no = %s\n", cube->no);
	printf("cube->so = %s\n", cube->so);
	printf("cube->ea = %s\n", cube->ea);
	printf("cube->we = %s\n", cube->we);
	return (1);
}
