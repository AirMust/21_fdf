/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:51:45 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:06:47 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(int n, int fd, long long mn)
{
	int		nb;

	nb = n;
	while (nb > 0)
	{
		nb /= 10;
		mn *= 10;
	}
	mn /= 10;
	while (mn > 0)
	{
		ft_putchar_fd(n / mn + '0', fd);
		n %= mn;
		mn /= 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putstr_fd("0", fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		ft_print_nbr(n, fd, 1);
	}
}
