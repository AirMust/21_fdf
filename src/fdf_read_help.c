/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:49:29 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/13 16:33:48 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_map	*fill_point(t_map *map, int x, int y, int z)
{
	map->points[y][x].x = x;
	map->points[y][x].y = y;
	map->points[y][x].z = z;
	map->points[y][x].color = 0xFF0000;
	if (map->points[y][x].z > map->depth_max)
		map->depth_max = map->points[y][x].z;
	if (map->points[y][x].z < map->depth_min)
		map->depth_min = map->points[y][x].z;
	return (map);
}
