/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:20:10 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/15 16:30:30 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		**ft_copy_matrix(int **src, int size)
{
	int **dst;
	int i;
	int j;

	if (!(dst = ft_create_matrix_int(size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			dst[i][j] = src[i][j];
	}
	return (dst);
}
