/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:42:23 by slynell           #+#    #+#             */
/*   Updated: 2020/10/20 20:53:22 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint_fd(t_list *alst, int fd)
{
	while (alst)
	{
		ft_putstr_fd((char*)alst->content, fd);
		alst = alst->next;
	}
	ft_putstr_fd("\n", fd);
}
