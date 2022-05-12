/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:39:14 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/18 18:13:21 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*res;

	len = ft_intlen(n) - 1;
	if (((res = ft_memalloc(len + 2)) != NULL))
	{
		if (n < 0)
			res[0] = '-';
		if (n == 0)
		{
			res[0] = ABS(n) + '0';
			return (res);
		}
		while (n != 0)
		{
			res[len] = ABS(n % 10) + '0';
			n /= 10;
			len--;
		}
		return (res);
	}
	return (NULL);
}
