/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:58:20 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 13:56:14 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	size_t			i;
	int				flag;
	long long int	x;

	x = 0;
	flag = 1;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || \
	nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			flag = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		x = x * 10 + (long long int)(nptr[i++] - 48);
		if (x > 9223372036854775807)
			return (flag == -1 ? 0 : -1);
	}
	return ((int)x * flag);
}
