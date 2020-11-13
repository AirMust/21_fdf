/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/11/13 16:34:53 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/header/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIN_WIDTH			1280
# define WIN_HEIGHT			720

typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			f;
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

typedef struct		s_dims
{
	int			height;
	int			width;
}					t_dims;

/*
** ========================== FUNCTION MAIN ==============================
*/

void				fdf_error(char *error);
t_mlx				*fdf_create(char *name_map);
t_map				*fdf_read_map(char *name_map);
void				fdf_render(t_mlx *mlx);
t_point				fdf_project(t_point point, t_mlx *mlx);
t_map				*fill_point(t_map *map, int x, int y, int z);

void				image_set_pixel(t_image *image, int x, int y, int color);
void				clear_image(t_image *image);
t_image				*new_image(t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
#endif
