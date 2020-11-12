/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:26:57 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/21 14:56:25 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_qpop(t_queue **head, size_t type_size)
{
	void	*data;
	t_queue	*tmp;

	if (!(*head))
		return (NULL);
	if (!(data = ft_memalloc(type_size)))
		return (NULL);
	ft_memcpy(data, (*head)->data, type_size);
	tmp = *head;
	*head = tmp->next;
	free(tmp->data);
	free(tmp);
	return (data);
}
