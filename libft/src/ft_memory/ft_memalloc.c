/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:54:30 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 14:54:33 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*mem;

	if ((int)size < 0 || (int)size + 1 == 0)
		return (0);
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	return (ft_memset(mem, 0, size));
}
