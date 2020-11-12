/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:19:50 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:19:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*str;
	int				i;
	int				j;
	int				k;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s) - 1;
	j = 0;
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j++;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	if (i - j + 1 <= 0)
		return ("");
	str = (char*)malloc(sizeof(char) * (i - j + 2));
	if (str == NULL)
		return (NULL);
	k = -1;
	while (++k <= i - j)
		str[k] = s[k + j];
	str[k] = 0;
	return (str);
}
