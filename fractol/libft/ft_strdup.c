/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:26:02 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/03 15:31:59 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(s2 = ft_memalloc(len)))
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
