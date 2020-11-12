/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:58:41 by slynell           #+#    #+#             */
/*   Updated: 2020/09/21 14:58:42 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix_int(int **matrix, int count)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("Matrix: \n");
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			ft_printf("%d ", matrix[i][j]);
		ft_printf("\n");
	}
}
