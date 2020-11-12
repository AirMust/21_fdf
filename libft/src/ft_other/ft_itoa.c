/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:58:20 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 10:58:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		counter(int n)
{
	int			result;

	result = 0;
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n /= 10;
	}
	return (result);
}

static char		*make_str(int flag, int n, int len)
{
	char		*res;

	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	while (len-- > 0)
	{
		if (flag == -1 && len == 0)
		{
			res[len] = '-';
			break ;
		}
		res[len] = '0' + (n % 10);
		n /= 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	int			flag;
	int			len;

	flag = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = counter(n);
	if (n < 0)
	{
		flag = -1;
		n *= -1;
	}
	return (make_str(flag, n, len));
}
