/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/03 16:50:58 by vimercie         ###   ########lyon.fr   */
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
# define Z			122
# define Q			113
# define W 			119
# define A 			97
# define S 			115
# define D 			100
# define LEFT		65361
# define RIGHT		65363
# define X 			120
# define O 			111
# define P 			112
# define R 			114
# define G 			103
# define B 			98
# define ESC		65307
# define TAB		48
# define SPACE		49

// Colors
# define WHITE		0xFFFFFF
# define GREY		0x808080

// Raycast
# define PI			3.1415926535
# define R_ONE_DEG	0.0174533
# define R_ANGLE	0.000636
# define HR			1080 / 2
# define RES		1920
# define FOV	    50

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
	int		bytes_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_color
{
	char	*hex;
	int		int_hex;
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
	int		mx;
	int		my;
	int		dof;
	char	type;
	double	a_tan;
}			t_cast;

typedef struct s_asset
{
	t_data	img;
	char	*path;
	int		width;
	int		height;
}				t_asset;

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
	double		fov_radian;
	t_cast		v_ray[RES];
	t_cast		h_ray[RES];
	t_cast		ray[RES];
	int			display_status;
	t_player	p;
	char		**file;
	char		**map;
	int			map_width;
	int			map_height;
	t_asset		no;
	t_asset		so;
	t_asset		we;
	t_asset		ea;
	t_color		floor;
	t_color		ceiling;
	bool		key_w;
	bool		key_a;
	bool		key_s;
	bool		key_d;
	bool		key_left;
	bool		key_right;
}				t_cube;


// 	parsing
int		parsing(char *filename, t_cube *cube);
int		parse_elements(t_cube *cube);
int		parse_description(t_cube *cube);

int		get_fd(char *filename);
char	**file_to_tab(char *filename);
char	*get_next_word(char *str);
char	*dup_and_fill(char *src, char c, size_t size, bool ow_last_char);

int		get_map_dimensions(char **file, t_cube *cube);

void	get_player_coordinates(t_player *p, char **map);
t_point	get_player_pos(char **map);
double	get_player_angle(char direction);

bool	wall_sonar(int x, int y, char **map);

bool	check_file_extension(char *filename, char *format);

char	*color_int_to_hex(int n);
int		color_hex_to_int(char *str);

// init
void	init_mlx(t_cube *cube);
void	init_cube(t_cube *cube);
void	init_assets(t_cube *cube);
int		init_map(t_cube *cube);
void	set_texture(t_asset *asset, void *mlx);
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
void	draw_segment(t_cube *cube, t_point a, t_point b, int color);
void	draw_vertical_segment(t_cube *cube, int x, t_point pos, int color);
void	draw_square(t_cube *cube, double x, double y);
void	draw_map(t_cube *cube);
void	draw_player(t_cube *cube);
void	draw_dot(t_cube *cube, double x, double y);
void	draw_perspective(t_cube *cube);
void	draw_texture(t_cube *cube);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_custom_pixel_put(t_data *img, int pos, int color);

//	raycast
void	horizontal_ray_maths(t_cube *cube, t_cast *r, t_player *p);
void	horizontal_step(t_cube *cube, t_cast *r);
void	horizontal_raycast(t_cube *cube);

void	vertical_ray_maths(t_cube *cube, t_cast *r, t_player *p);
void	vertical_step(t_cube *cube, t_cast *r);
void	vertical_raycast(t_cube *cube);

// ray_utils
int		p_map_pos(t_cube *cube, char c);
int		is_in_map(t_cube *cube, int x, int y);
double	reset_angle(double angle);
void	draw_closest_ray(t_cube *cube);

//	display
int		gameloop(t_cube *cube);
int		get_color(t_data img, t_point pos);

//	events
int		key_pressed_events(int keycode, t_cube *cube);
int		key_release_events(int keycode, t_cube *cube);
void	move_player(t_cube *cube);

#endif
