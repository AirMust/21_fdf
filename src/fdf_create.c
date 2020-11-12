/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/13 02:10:35 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

t_mlx	*fdf_create(char *name_map)
{

	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		fdf_error("Error: can't init mlx\n");
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
								WIN_HEIGHT, name_map);
	mlx->cam = ft_memalloc(sizeof(t_cam));
	mlx->mouse = ft_memalloc(sizeof(t_mouse));
	mlx->image = new_image(mlx);
	mlx->cam->x = 1.0;
	mlx->cam->y = 1.0;
	mlx->cam->f = -1;
	mlx->cam->scale = 50;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
	mlx->map = fdf_read_map(name_map);
	return (mlx);
}
