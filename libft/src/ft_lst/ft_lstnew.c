/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:34:38 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/20 21:35:03 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = malloc(content_size);
		if (temp->content == NULL)
		{
			free(temp);
			return (NULL);
		}
		temp->content = ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = NULL;
	return (temp);
}
