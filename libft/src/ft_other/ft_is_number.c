/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:00:51 by antondob          #+#    #+#             */
/*   Updated: 2020/11/14 02:43:15 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *str)
{
	if (!str || !(*str))
		return (0);
	if (!(ft_strchr("+-", *str)) && !(ft_isdigit(*str)))
		return (0);
	if (ft_strchr("+-", *str) && !(*(++str)))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}
