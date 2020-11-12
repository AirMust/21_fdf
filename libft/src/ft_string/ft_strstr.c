/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:19:50 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:19:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	const char		*s1;
	const char		*s2;
	size_t			i;
	int				flag;

	if (*needle == 0)
		return ((char*)haystack);
	i = 0;
	while (i < ft_strlen(haystack))
	{
		s1 = haystack + i;
		s2 = needle;
		flag = 1;
		while (*s2 && flag)
		{
			if (!(*s1) || *s1 != *s2)
				flag = 0;
			s1++;
			s2++;
		}
		if (flag)
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
