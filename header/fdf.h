/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/11/12 15:56:53 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
#include <fcntl.h>
# include "../libft/header/libft.h"
# include "../minilibx_macos/mlx.h"
// # include "ft_x11.h"
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720

typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}					t_cam;

typedef struct		s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}					t_point;

typedef struct		s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_point		**points;
}					t_map;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}					t_mlx;

typedef struct		s_line
{
	t_point		start;
	t_point		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}					t_line;

/*
** ========================== FUNCTION LIST TEXT ==============================
*/

void				fdf_error(char *error);
void				image_set_pixel(t_image *image, int x, int y, int color);
void				clear_image(t_image *image);
int					lineclip(t_point *p1, t_point *p2);
t_image				*new_image(t_mlx *mlx);

#endif
