/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/12 15:19:45 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

t_point rotate(t_point p, t_cam *r)
{
	t_point v;
	double x;
	double y;
	double z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

t_point project_vector(t_point v, t_mlx *mlx)
{
	ft_printf("%lf, %lf, %lf - ", v.y, v.x, v.z);
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1) / 2.0f;
	v.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	ft_printf("%lf, %lf, %lf\n", v.y, v.x, v.z);

	return (v);
}

int clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

double ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int line_process_point(t_mlx *mlx, t_line *l, t_point *p1,
					   t_point *p2)
{
	double percent;

	if (p1->x < 0 || p1->x >= WIN_WIDTH || p1->y < 0 || p1->y >= WIN_HEIGHT || p2->x < 0 || p2->x >= WIN_WIDTH || p2->y < 0 || p2->y >= WIN_HEIGHT)
		return (1);
	percent = (l->dx > l->dy ? ft_ilerp((int)p1->x, (int)l->start.x, (int)l->stop.x)
							 : ft_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y));
	image_set_pixel(mlx->image, (int)p1->x, (int)p1->y, clerp(p1->color, p2->color, percent));
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

void line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_line line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!lineclip(&p1, &p2))
		return;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (line_process_point(mlx, &line, &p1, &p2))
			break;
}

void render(t_mlx *mlx)
{
	int i;
	int j;
	t_point v;
	t_map *map;

	map = mlx->map;
	clear_image(mlx->image);
	i = -1;
	while(++i < map->height){
		j = -1;
		while(++j < map->width){
			v = project_vector(map->points[i][j], mlx);
			if (i + 1 < map->height)
				line(mlx, v, project_vector(map->points[i + 1][j], mlx));
			if (j + 1 < map->width)
				line(mlx, v, project_vector(map->points[i][j + 1], mlx));
		}
	}

	// ft_printf("{x: %lf y: %lf z: %d, color: %d}, ", map->points[x][y].x, map->points[x][y].y, map->points[x][y].z, map->points[x][y].color);

	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

void fdf_print_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	ft_printf("height: %d, width: %d, max: %d, min: %d\n", map->height, map->width, map->depth_max, map->depth_min);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ft_printf("{x: %lf y: %lf z: %d, color: %d}, ", map->points[i][j].x, map->points[i][j].y, map->points[i][j].z, map->points[i][j].color);
		}
	}
}

t_map *fdf_read_map(char *name_map)
{
	// t_list	*lst;
	char *temp_line;	   // Ну тут понятно
	char *line;			   // Строка после удаления пробельных символов
	char *result_line;	   // Склейка всех строк через \n
	char **lines;		   // Массив строк после сплита result_line
	char **values_in_line; // Массив строк после сплита result_line
	t_map *map;
	int fd;
	int i;
	int j;
	int height;
	int width;
	height = 0;
	width = 0;
	result_line = NULL;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		fdf_error("Error: can't open file\n");
	while (get_next_line(fd, &temp_line) > 0)
	{
		i = 0;
		// Так этими двумя строками мы удаляем пробельные символы вначалеи в конце, на всякий случай
		line = ft_strtrim(temp_line);
		ft_strdel(&temp_line);
		// Этим циклом мы пробегаем по строке и удаляем парные пробельные символы, то есть в карте
		// у нас может быть хоший случай типо 1_23_43, где _ - это пробел, то есть высоты карты идут
		// через один пробел, а может быть и такой случай 0__43__43 => 0_43_43 - результат работы

		while (i < (int)ft_strlen(line))
		{
			if (line[i] == ' ' && line[i + 1] == ' ')
			{
				temp_line = line;
				line = ft_strmerge(ft_strsub(line, 0, i), ft_strsub(line, i + 1, ft_strlen(line)));
				ft_strdel(&temp_line);
			}
			i++;
		}
		// Тут мы все склеиваем через \n чтоб потом раскидать по массивы, далее мы считываем "ширину" - карты
		// очевидно что для каждой строки должна быть одинаковая ширина, это мы и проверяем, если хоть в какой-то
		// строке не так, то все плохо, далее мы подсчитываем "высоту" карты ну и создаем массив двумерный
		result_line = ft_strmerge(result_line, ft_strjoin("\n", line));
		if (height == 0)
			width = ft_countwords(line, ' ');
		if (width != ft_countwords(line, ' '))
			fdf_error("Erorr: width\n");
		ft_strdel(&line);
		height += 1;
	}
	i = -1;
	map = ft_memalloc(sizeof(t_map *));
	map->height = height;
	map->width = width;
	map->depth_max = INT16_MIN;
	map->depth_min = INT32_MAX;
	if ((map->points = (t_point **)ft_memalloc(sizeof(t_point *) * (height + 1))) == NULL)
		fdf_error("Error: not memory points\n");
	lines = ft_strsplit(result_line, '\n');
	while (++i < height)
	{
		if ((map->points[i] = (t_point *)ft_memalloc(sizeof(t_point) * (width + 1))) == NULL)
			fdf_error("Error: not memory points\n");
		values_in_line = ft_strsplit(lines[i], ' ');
		j = -1;
		while (++j < width)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(values_in_line[j]);
			map->points[i][j].color = clerp(0xFF0000, 0xFFFFFF, ft_ilerp(map->points[i][j].z,
				0, 10));
			if (map->points[i][j].z > map->depth_max)
				map->depth_max = map->points[i][j].z;
			if (map->points[i][j].z < map->depth_min)
				map->depth_min = map->points[i][j].z;
		}
		ft_strsplitfree(&values_in_line);
	}
	ft_strsplitfree(&lines);
	// fdf_print_map(map);
	ft_strdel(&result_line);
	return (map);
}

t_mlx *fdf_create(char *name_map)
{

	t_mlx *mlx;
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		fdf_error("Error: can't init mlx\n");
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
								 WIN_HEIGHT, name_map);
	mlx->cam = ft_memalloc(sizeof(t_cam));
	mlx->mouse = ft_memalloc(sizeof(t_mouse));
	mlx->image = new_image(mlx);
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 10;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	mlx->map = fdf_read_map(name_map);
	return (mlx);
}

int main(int argc, char **argv)
{
	// t_map	*map;
	t_mlx *mlx;
	// int		fd;
	(void)argv;

	if (argc < 2)
		fdf_error("Error: not enough arguments");
	mlx = fdf_create(argv[1]);
	render(mlx);
	// mlx_key_hook(mlx->window, hook_keydown, mlx);
	// mlx_hook(mlx->window, 4, 0, hook_mousedown, mlx);
	// mlx_hook(mlx->window, 5, 0, hook_mouseup, mlx);
	// mlx_hook(mlx->window, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
