/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:19:33 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:06:36 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*strsrc;
	size_t			i;

	i = 0;
	strsrc = (unsigned char*)src;
	while (i < len)
	{
		if (strsrc[i] == (unsigned char)c)
			return (strsrc + i);
		i++;
	}
	return (NULL);
}
