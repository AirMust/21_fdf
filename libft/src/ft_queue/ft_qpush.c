/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:45:39 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/04 01:11:46 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qpush(t_queue **head, void *data, size_t type_size)
{
	t_queue *new;
	t_queue *tmp;

	if (!(new = ft_memalloc(sizeof(t_queue))))
		return ;
	if (!(new->data = ft_memalloc(sizeof(type_size))))
	{
		free(new);
		new = NULL;
		return ;
	}
	ft_memcpy(new->data, data, type_size);
	new->next = NULL;
	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
