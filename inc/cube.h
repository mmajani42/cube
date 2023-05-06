/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/06 20:00:59 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../Libft/inc/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define WIN_X		1920
# define WIN_Y		1080
# define PI			3.1415926535
# define Z			122
# define Q			113
# define W 			119
# define A 			97
# define S 			115
# define X 			120
# define D 			100
# define O 			111
# define P 			112
# define R 			114
# define G 			103
# define B 			98
# define ESC		65307
# define TAB		48
# define SPACE		49
# define PLUS		65451
# define MINUS		65454
# define LEFT		65361
# define RIGHT		65363
# define DOWN		65364
# define UP			65362
# define FOV		70

typedef struct s_point
{
	double	x;
	double	y;
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

typedef struct s_player
{
	double	angle;
	t_point	pos;
	t_point	vec;
}			t_player;

typedef struct s_cast
{
	double	a;
	double	x;
	double	y;
	double	yo;
	double	xo;
	double	size;
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
}			t_cast;

typedef struct s_cube
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			win_x;
	int			win_y;
	double		ts;
	double		off_x;
	double		off_y;
	int			display_status;
	int			max_line_size;
	int			map_height;
	char		**file;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_cast		v_ray[FOV];
	t_cast		h_ray[FOV];
	t_color		floor;
	t_color		ceiling;
	t_player	p;
}				t_cube;

void	cube_tester(t_cube *cube);

// 	parsing
int		parsing(char *filename, t_cube *cube);
int		parse_elements(t_cube *cube);
int		parse_description(t_cube *cube);

int		get_fd(char *filename);
char	**file_to_tab(char *filename);
char	*get_next_word(char *str);
char	*dup_and_fill(char *src, char c, int size, bool ow_last_char);

int		get_map_dimensions(char **file, t_cube *cube);

void	get_player_coordinates(t_player *p, char **map);
t_point	get_player_pos(char **map);
t_point	get_player_vec(char direction);

bool	wall_sonar(int x, int y, char **map);

bool	check_file_extension(char *filename, char *format);

// init
void	init_cube(t_cube *cube);
int		init_map(t_cube *cube);
void	set_tile_size(t_cube *cube);
void	set_player(t_cube *cube);

// checking
bool	is_rgb(char **tab);
bool	is_wall(char *line);
bool	is_valid_map_line(char *line);
bool	is_map_bordered(char **map);
bool	is_unique_player(char **map);

// errors
int		print_error(char *error);

// cleaning
void	free_tab(char **tab);
void	free_cube(t_cube *cube);

//	drawing
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_segment(t_cube *cube, t_point a, t_point b, int color);
void	draw_square(t_cube *cube, double x, double y);
void	draw_map(t_cube *cube);
void	draw_player(t_cube *cube);
void	draw_dot(t_cube *cube, double x, double y);

//	raycast
void	horizontal_raycast(t_cube *cube);
void	vertical_raycast(t_cube *cube);
void	draw_closest_ray(t_cube *cube);

// ray_utils
int		hit(t_cube *cube, int mx, int my);
int		p_map_pos(t_cube *cube, char c);
int		is_in_map(t_cube *cube, int x, int y);

//	display
void	clear_image(t_cube *cube);
void	display_axis(t_cube *cube);
void	display_handling(t_cube *cube);
void	print_tab(char **tab);

//	events
int		key_events(int keycode, t_cube *cube);
void	change_player_vector(t_cube *cube, int key);

#endif
