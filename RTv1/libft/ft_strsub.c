/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:52:47 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/16 12:14:38 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!(res = ft_memalloc(len + 1)) || s == NULL)
		return (NULL);
	ft_strncpy(res, &s[start], len);
	res[len] = '\0';
	return (res);
}
