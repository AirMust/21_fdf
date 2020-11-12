/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 02:06:07 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/11/12 03:37:25 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(EXIT_FAILURE);
}
