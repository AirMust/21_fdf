/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:53:36 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 13:53:42 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_array_min(int *array, int len)
{
	int		i;
	int		min;

	min = INT32_MAX;
	i = -1;
	while (++i < len)
		if (min > array[i])
			min = array[i];
	return (min);
}
