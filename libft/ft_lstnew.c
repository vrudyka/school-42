/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:07:32 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/16 17:05:30 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
	}
	else
	{
		res->content = ft_memalloc(content_size);
		ft_memmove(res->content, content, content_size);
		res->content_size = content_size;
		res->next = NULL;
	}
	return (res);
}
