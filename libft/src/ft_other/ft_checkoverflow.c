/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkoverflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:44:46 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/14 21:49:11 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		trim_nul_str(char *str, char *before)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		before[++j] = str[i];
		i++;
	}
	while (str[i] == '0' && str[i + 1])
		i++;
	while (str[i])
	{
		before[++j] = str[i];
		i++;
	}
	before[++j] = 0;
	if (before[0] == '-' && before[1] == '0')
	{
		before[0] = '0';
		before[1] = 0;
	}
}

int				ft_checkoverflow(int nbr, char *str)
{
	char	*before;
	char	*after;
	int		len;
	int		result;

	len = ft_strlen(str);
	before = ft_memalloc(len + 1);
	trim_nul_str(str, before);
	after = ft_itoa(nbr);
	result = (ft_strcmp(before, after) ? 1 : 0);
	free(before);
	free(after);
	return (result);
}
