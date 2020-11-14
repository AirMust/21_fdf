/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:28:10 by antondob          #+#    #+#             */
/*   Updated: 2020/11/14 02:34:40 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	validate_number(char *number)
{
	if (!ft_is_number(number))
		fdf_error("Error: map is invalid for some reason\n");
	if (ft_checkoverflow(ft_atoi(number), number))
		fdf_error("Error: INT overflow\n");
}

void	validate_line(char *line)
{
	int i;

	i = -1;
	if (!*line)
		fdf_error("Error: map is invalid for some reason\n");
	while (line[++i])
		if ((line[i] > '9' || line[i] < '0') &&
			line[i] != ' ' && line[i] != '+' && line[i] != '-')
			fdf_error("Error: invalid symbols in map\n");
}

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
