/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:52:59 by slynell           #+#    #+#             */
/*   Updated: 2020/10/22 17:53:43 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_array_max(int *array, int len)
{
	int	i;
	int	max;

	max = INT32_MIN;
	i = -1;
	while (++i < len)
		if (max < array[i])
			max = array[i];
	return (max);
}
