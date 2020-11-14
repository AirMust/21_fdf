/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:32:51 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/14 15:27:36 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_map	*fdf_create_map(t_dims dims)
{
	t_map	*map;
	int		i;

	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		fdf_error("Error: not memory map\n");
	map->height = dims.height;
	map->width = dims.width;
	map->depth_max = INT32_MIN;
	map->depth_min = INT32_MAX;
	if ((map->points = (t_point **)ft_memalloc(sizeof(t_point *) *
			(dims.height))) == NULL)
		fdf_error("Error: not memory points\n");
	i = -1;
	while (++i < dims.height)
		if ((map->points[i] = (t_point *)ft_memalloc(sizeof(t_point) *
				(dims.width))) == NULL)
			fdf_error("Error: not memory points\n");
	return (map);
}

int		fdf_get_color(int value, int max, int min)
{
	int		c1;
	int		c2;
	double	del;

	(void)value;
	c1 = 0xFF0000;
	c2 = 0x0000FF;
	del = (c1 - c2) / ((max - min) == 0 ? 1 : max - min) * 1.0f;
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
			map->points[i][j].color = fdf_get_color(map->points[i][j].z,
				map->depth_max, map->depth_min);
	}
}

t_map	*fdf_parse_map(char *line, t_dims dims)
{
	t_map	*map;
	char	**lines;
	char	**values_in_line;
	int		i;
	int		j;

	map = fdf_create_map(dims);
	lines = ft_strsplit(line, '\n');
	i = -1;
	while (++i < dims.height)
	{
		j = -1;
		values_in_line = ft_strsplit(lines[i], ' ');
		while (++j < dims.width)
		{
			validate_number(values_in_line[j]);
			fill_point(map, j, i, ft_atoi(values_in_line[j]));
		}
		ft_strsplitfree(&values_in_line);
	}
	ft_strsplitfree(&lines);
	fdf_set_color(map);
	return (map);
}

t_map	*fdf_read_map(int fd)
{
	t_map	*map;
	char	*line;
	char	*result_line;
	t_dims	dims;

	dims.height = 0;
	dims.width = 0;
	result_line = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		validate_line(line);
		result_line = ft_strmerge(result_line, ft_strjoin("\n", line));
		if (dims.height == 0)
			dims.width = ft_countwords(line, ' ');
		if (dims.width != ft_countwords(line, ' '))
			fdf_error("Error: map is not rectangular\n");
		ft_strdel(&line);
		dims.height += 1;
	}
	if (!dims.width)
		fdf_error("Error: map is empty\n");
	ft_strdel(&line);
	map = fdf_parse_map(result_line, dims);
	ft_strdel(&result_line);
	return (map);
}
