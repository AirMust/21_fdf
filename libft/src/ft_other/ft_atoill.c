/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:55:55 by slynell           #+#    #+#             */
/*   Updated: 2020/07/26 13:47:48 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspace(char c)
{
	return ((c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ') ? 1 : 0);
}

long long	ft_atoill(const char *str)
{
	int			i;
	long long	n;
	int			s;
	int			mn;

	i = 0;
	n = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		IF_TRUE(str[i] == '-', s = -1);
		i++;
	}
	mn = i;
	while (IS_DIGIT(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
		if (i - mn > 11)
			return (2147483648);
	}
	return (n * s);
}
