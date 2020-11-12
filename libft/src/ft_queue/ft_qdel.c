/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:58:35 by antondob          #+#    #+#             */
/*   Updated: 2020/09/21 14:57:49 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qdel(t_queue **head)
{
	t_queue *tmp1;
	t_queue *tmp2;

	if (!*head)
		return ;
	tmp1 = *head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
	*head = NULL;
}
