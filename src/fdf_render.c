/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/13 14:45:09 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int fdf_check_point(t_point *point)
{
	if (point->x < 0 || point->x >= WIN_WIDTH || point->y < 0 || point->y >= WIN_HEIGHT)
		return (1);
	return (0);
}

int fdf_draw_point(t_mlx *mlx, t_line *l, t_point *p1,
					   t_point *p2)
{
	if (fdf_check_point(p1) || fdf_check_point(p2))
		return (1);
	image_set_pixel(mlx->image, (int)p1->x, (int)p1->y, p1->color);
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void fdf_draw_line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_line line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (fdf_draw_point(mlx, &line, &p1, &p2))
			break;
}

void	fdf_render(t_mlx *mlx)
{
	t_map	*map;
	t_point	v;
	int		i;
	int		j;

	map = mlx->map;
	clear_image(mlx->image);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			v = fdf_project(map->points[i][j], mlx);
			fdf_draw_line(mlx, v, v);
			if (i + 1 < map->height)
				fdf_draw_line(mlx, v, fdf_project(map->points[i + 1][j], mlx));
			if (j + 1 < map->width)
				fdf_draw_line(mlx, v, fdf_project(map->points[i][j + 1], mlx));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
