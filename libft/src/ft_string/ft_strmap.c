/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:19:50 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:19:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;
	size_t			n;

	n = ft_strlen(s);
	if (n + 1 == 0)
		return (NULL);
	str = (char*)ft_memalloc(n + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
