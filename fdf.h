/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:47:08 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/07 10:33:01 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH 1280
# define HEIGHT 800

# define MOUSE_DOWN 4
# define MOUSE_UP 5
# define MOUSE_MOVE 6

# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define ORANGE 0xFFA500
# define WHITE 0xFFFFFF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define YELLOW 0xFFFF00
# define OLIVE 0x808000
# define LIME 0x00FF00
# define GREEN 0x008000
# define AQUA 0x00FFFF
# define TEAL 0x008080
# define NAVY 0x000080
# define FUCHSIA 0xFF00FF
# define PURPLE 0x800080

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			sizel;
	int			endian;
}				t_image;

typedef struct	s_bres
{
	int			err;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_bres;

typedef struct	s_render
{
	int			rows;
	int			check;
	int			cols;
	t_bres		*bres;
}				t_render;

typedef struct	s_rot_point
{
	double		act_px;
	double		act_py;
	double		act_pz;
	double		px;
	double		py;
	double		pz;
}				t_rot_point;

typedef struct	s_vector
{
	int			x;
	int			y;
	int			z;
	int			d2x;
	int			d2y;
	int			color;
}				t_vector;

typedef struct	s_mouse
{
	int			lastx;
	int			lasty;
	int			x;
	int			y;
	int			button1;
}				t_mouse;

typedef struct	s_mlx
{
	int			fd;
	char		*name;
	void		*mlx;
	void		*win;
	t_vector	**map;
	t_image		*image;
	t_render	info;
	t_mouse		mouse;
	int			depth_max;
	int			depth_min;
	int			scale;
	double		depth;
	double		anglex;
	double		angley;
	int			move_lr;
	int			move_ud;
}				t_mlx;

void			ft_render(t_mlx *mlx);

void			init_mlx(t_mlx *mlx);
void			init(t_mlx *mlx);

int				expose_hook(t_mlx *mlx);
void			erase(t_mlx *mlx);

int				key_hook(int key, t_mlx *mlx);
void			ft_xy_trans(int key, t_mlx *mlx);
int				ft_close(void);
void			ft_depth(int key, t_mlx *mlx);
void			ft_scale(int key, t_mlx *mlx);

int				mouse_down(int button, int x, int y, t_mlx *mlx);
int				ft_rotate_map(int x, int y, t_mlx *mlx);

int				ft_read(t_mlx *mlx);
int				ft_alloc_tab(t_mlx *mlx);
int				ft_col_row(t_mlx *mlx, char *line);

void			set_pixel(t_image *image, int x, int y, int color);
void			clear_image(t_mlx *mlx);
t_image			*del_image(t_image *image, t_mlx *mlx);
t_image			*init_img(t_mlx *mlx);

void			ft_calculate(t_mlx *mlx, t_vector *pt);
void			rotate(t_mlx *mlx, t_rot_point *rp);
void			calcule_coord(t_mlx *mlx);

int				get_highest(t_vector *p1, t_vector *p2, t_mlx *mlx);
int				choose_color(int p1);
int				cnv_dbl_int(double num);
int				ft_abs(int num);

int				create_x(t_mlx *win, int x);
int				create_y(t_mlx *win, int y);
t_bres			*bres_const(t_vector *p1, t_vector *p2);

#endif
