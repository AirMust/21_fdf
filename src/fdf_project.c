/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/13 02:12:46 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_point		fdf_projection_isometric(t_point point, t_cam *r)
{
	t_point	temp_point;
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_x = point.x;
	temp_z = point.z;
	temp_point.x = cos(r->y) * temp_x + sin(r->y) * temp_z;
	temp_point.z = -sin(r->y) * temp_x + cos(r->y) * temp_z;
	temp_y = point.y;
	temp_z = temp_point.z;
	temp_point.y = cos(r->x) * temp_y - sin(r->x) * temp_z;
	temp_point.z = sin(r->x) * temp_y + cos(r->x) * temp_z;
	temp_point.color = point.color;
	return (temp_point);
}

// Проекция Косоугольная
t_point		fdf_projection_oblique(t_point point, t_cam *r)
{
	t_point	temp_point;
	int		f;

	f = 1;
	temp_point.x = (-1) * f * cos(r->y) * point.z + point.x;
	temp_point.y = (-1) * f * sin(r->y) * point.z + point.y;
	temp_point.z = point.z;
	temp_point.color = point.color;
	return (temp_point);
}

t_point		fdf_project(t_point point, t_mlx *mlx)
{
	point.x -= (double)(mlx->map->width - 1) / 2.0f;
	point.y -= (double)(mlx->map->height - 1) / 2.0f;
	point.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	point = (mlx->cam->f < 0 ? fdf_projection_isometric(point, mlx->cam)
							: fdf_projection_oblique(point, mlx->cam));
	point.x *= mlx->cam->scale;
	point.y *= mlx->cam->scale;
	point.x += mlx->cam->offsetx;
	point.y += mlx->cam->offsety;
	return (point);
}
