/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:58:20 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 10:58:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	int		l;

	if (!*needle)
		return ((char*)haystack);
	n = ft_strlen(needle);
	if (len == 0)
		return (NULL);
	l = 1;
	while (n < len && *haystack != 0 && ft_strncmp(haystack, needle, n))
	{
		len--;
		haystack++;
	}
	l = ft_strncmp(haystack, needle, n);
	if (l != 0)
		return (NULL);
	return ((char*)haystack);
}
