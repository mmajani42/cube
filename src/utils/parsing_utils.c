/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:49:14 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 01:50:25 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	color_hex_to_int(char *str)
{
	int	res;
	int	digit;
	int	i;

	res = 0;
	digit = 0;
	i = 0;
	if (ft_strncmp(str, "0x", 2) == 0)
		i += 2;
	while (ft_isxdigit(str[i]))
	{
		if (ft_isdigit(str[i]))
			digit = str[i] - '0';
		else
			digit = ft_tolower(str[i]) - 'a' + 10;
		res = res * 16 + digit;
		i++;
	}
	return (res);
}

char	*color_int_to_hex(int n)
{
	char	hex[17];
	char	*res;

	if (n < 0 || n > 255)
		return (NULL);
	ft_strlcpy(hex, "0123456789ABCDEF", 17);
	res = ft_calloc(3, sizeof(char));
	if (n < 16)
	{
		res[0] = hex[n % 16];
		res[1] = '0';
	}
	else
	{
		res[0] = hex[(n / 16) % 16];
		res[1] = hex[n % 16];
	}
	return (res);
}

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

int	count_file_lines(char *filename)
{
	char	*buffer;
	int		fd;
	int		res;

	res = 0;
	fd = get_fd(filename);
	buffer = get_next_line(fd);
	while (buffer)
	{
		res++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (res);
}

char	**file_to_tab(char *filename)
{
	char	**res;
	char	*buffer;
	int		fd;
	int		file_height;
	int		i;

	i = 0;
	file_height = count_file_lines(filename);
	if (file_height == 0)
		return (NULL);
	fd = get_fd(filename);
	buffer = get_next_line(fd);
	res = ft_calloc(file_height + 1, sizeof(char *));
	while (buffer)
	{
		res[i] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	close(fd);
	return (res);
}
