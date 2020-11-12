/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:19:33 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:06:36 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*strsrc;
	char	*strdest;
	size_t	i;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	strsrc = (char*)src;
	strdest = (char*)dest;
	while (n > 0)
	{
		n--;
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}
