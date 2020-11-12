/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:56:40 by slynell           #+#    #+#             */
/*   Updated: 2020/07/26 13:48:12 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_check_integer(char *str)
{
	int	i;

	i = 0;
	if (ft_strequ(str, "-") || ft_strequ(str, "+"))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != 0)
		return (0);
	i = ft_atoill(str) > INT32_MAX || ft_atoill(str) < INT32_MIN ? 0 : 1;
	return (i);
}
