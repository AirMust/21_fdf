/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:53:52 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 13:53:56 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_array_print(int *array, int length)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		ft_putnbr_fd(array[i], 1);
		ft_putchar(' ');
	}
}
