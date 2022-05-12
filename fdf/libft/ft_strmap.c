/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:28:29 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/06 15:55:55 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	size_t		len;
	char		*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	if (!(res = ft_memalloc(len)))
		return (NULL);
	while (i < (len - 1))
	{
		res[i] = (*f)(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
