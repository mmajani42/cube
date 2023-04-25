/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/25 19:32:54 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "../Libft/inc/libft.h"
# include <math.h>

# define WIN_X 3840 
# define WIN_Y 2160

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_color
{
	int		is_set;
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_cube
{
	void		*mlx;
	void		*mlx_win;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		ceiling;
	t_data		img;
	int			map_size_x;
	int			map_size_y;
	int			win_x;
	int			win_y;
	int			display_status;
}				t_cube;

void	init_parsing(t_cube *cube);

#endif
