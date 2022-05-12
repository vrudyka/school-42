/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:15:32 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/09 18:27:37 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*lstc;

	lstc = lst;
	while (lstc != NULL)
	{
		tmp = lstc->next;
		f(lstc);
		lstc = tmp;
	}
}
