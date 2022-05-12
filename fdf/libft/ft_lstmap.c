/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:20:54 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/09 19:21:10 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;
	t_list		*resc;
	t_list		*lstc;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lstc = lst;
	res = f(lstc);
	resc = res;
	lstc = lstc->next;
	while (lstc != NULL)
	{
		res->next = f(lstc);
		res = res->next;
		lstc = lstc->next;
	}
	res->next = NULL;
	return (resc);
}
