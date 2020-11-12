/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:51:45 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:06:47 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdest;
	size_t			i;
	unsigned char	q;

	q = (unsigned char)c;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	strsrc = (unsigned char*)src;
	strdest = (unsigned char*)dest;
	while (n > 0 && strsrc[i] != q)
	{
		n--;
		strdest[i] = strsrc[i];
		i++;
	}
	if (n > 0)
	{
		strdest[i] = strsrc[i];
		return ((void*)(strdest + i + 1));
	}
	return (NULL);
}
