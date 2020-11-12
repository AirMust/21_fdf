/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:58:23 by slynell           #+#    #+#             */
/*   Updated: 2020/07/25 14:01:56 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wint_t *s)
{
	register size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len++;
		len += *s > 0xFFFF;
		len += *s > 0x7FF;
		len += *s > 0x7F;
		++s;
	}
	return (len);
}
