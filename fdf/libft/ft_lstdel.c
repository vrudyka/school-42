/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:41:15 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/16 00:07:47 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*alstc;

	alstc = (*alst);
	while (alstc != NULL)
	{
		tmp = alstc->next;
		del(alstc->content, alstc->content_size);
		free(alstc);
		alstc = tmp;
	}
	*alst = NULL;
}
