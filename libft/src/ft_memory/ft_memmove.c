/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:09:41 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:15:06 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (src == NULL && dest == NULL)
		return (NULL);
	s1 = (char*)src;
	s2 = (char*)dest;
	if (s1 < s2)
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len-- > 0)
			*s2-- = *s1--;
	}
	else
		while (len-- > 0)
			*s2++ = *s1++;
	return (dest);
}
