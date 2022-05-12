/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:53:13 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/18 18:13:46 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*res;

	if (!(res = ft_memalloc(size + 1)))
		return (NULL);
	ft_memset(res, (int)'\0', size + 1);
	return (res);
}
