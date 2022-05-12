/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:23:07 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/09 18:52:47 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	while (len > 0)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	if (s[len] == c)
		return ((char*)&s[len]);
	return (NULL);
}
