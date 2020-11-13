/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/13 03:45:31 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_map	*fdf_create_map(int height, int width)
{
	t_map	*map;
	int		i;

	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		fdf_error("Error: not memory map\n");
	map->height = height;
	map->width = width;
	map->depth_max = INT32_MIN;
	map->depth_min = INT32_MAX;
	if ((map->points = (t_point **)ft_memalloc(sizeof(t_point *) * (height))) == NULL)
		fdf_error("Error: not memory points\n");
	i = -1;
	while (++i < height)
		if ((map->points[i] = (t_point *)ft_memalloc(sizeof(t_point) * (width))) == NULL)
			fdf_error("Error: not memory points\n");
	return (map);
}

int		fdf_get_color(int value, int max, int min)
{
	int	c1;
	int	c2;
	double	del;
	(void)value;
	c1 = 0xFF0000;
	c2 = 0x0000FF;
	del = (c1 - c2) / (max - min) * 1.0f;
	return (del * (value - min) + c2);
}

void	fdf_set_color(t_map *map)
{
	int	i;
	int	j;

	i = -1;

	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			map->points[i][j].color = fdf_get_color(map->points[i][j].z, map->depth_max, map->depth_min);
	}
}

t_map	*fdf_parse_map(char *line, int height, int width)
{
	t_map	*map;
	char	**lines;
	char	**values_in_line;
	int		i;
	int		j;

	map = fdf_create_map(height, width);
	lines = ft_strsplit(line, '\n');
	i = -1;
	while (++i < height)
	{
		j = -1;
		values_in_line = ft_strsplit(lines[i], ' ');
		while (++j < width)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(values_in_line[j]);
			map->points[i][j].color = 0xFF0000;
			if (map->points[i][j].z > map->depth_max)
				map->depth_max = map->points[i][j].z;
			if (map->points[i][j].z < map->depth_min)
				map->depth_min = map->points[i][j].z;
		}
		ft_strsplitfree(&values_in_line);
	}
	ft_strsplitfree(&lines);
	fdf_set_color(map);
	return (map);
}

t_map *fdf_read_map(char *name_map)
{
	t_map	*map;
	int		fd;
	char	*line;
	char	*result_line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	result_line = NULL;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: can't open file\n");
	while (get_next_line(fd, &line) > 0)
	{
		result_line = ft_strmerge(result_line, ft_strjoin("\n", line));
		if (height == 0)
			width = ft_countwords(line, ' ');
		if (width != ft_countwords(line, ' '))
			fdf_error("Error: width\n");
		ft_strdel(&line);
		height += 1;
	}
	ft_strdel(&line);
	map = fdf_parse_map(result_line, height, width);
	ft_strdel(&result_line);
	return (map);
}
