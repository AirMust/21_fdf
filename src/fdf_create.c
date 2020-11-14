/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:33:23 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/14 17:45:49 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_mlx	*fdf_create(char *name_map)
{
	t_mlx	*mlx;
	int		fd;

	if ((fd = open(name_map, O_RDONLY)) < 0)
		fdf_error("Error: can't open file\n");
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		fdf_error("Error: can't init mlx\n");
	mlx->map = fdf_read_map(fd);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
								WIN_HEIGHT, name_map);
	mlx->cam = ft_memalloc(sizeof(t_cam));
	mlx->mouse = ft_memalloc(sizeof(t_mouse));
	mlx->image = new_image(mlx);
	mlx->cam->x = 0.0;
	mlx->cam->y = 0.0;
	mlx->cam->f = -1;
	mlx->cam->scale = 50;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	return (mlx);
}
