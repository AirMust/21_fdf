/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddcontent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:51:45 by slynell           #+#    #+#             */
/*   Updated: 2020/10/20 21:33:49 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstaddcontent(t_list **alst, void *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)ft_lstnew(content, content_size);
	if (temp == NULL)
		return (0);
	ft_lstlink(alst, temp);
	return (1);
}
