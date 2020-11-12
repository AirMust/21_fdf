/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:36 by slynell           #+#    #+#             */
/*   Updated: 2020/09/21 14:57:24 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix_char(char ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}

void	ft_free_matrix_int(int ***matrix, int count_row)
{
	if (!matrix || !(*matrix))
		return ;
	while (--count_row >= 0)
		free((*matrix)[count_row]);
	free(*matrix);
	*matrix = NULL;
}

void	ft_delete_table(int ***table, int rows)
{
	if (!table || !(*table))
		return ;
	while (--rows >= 0)
		free((*table)[rows]);
	free(*table);
	*table = NULL;
}
