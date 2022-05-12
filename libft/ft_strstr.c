/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:37:20 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/06 14:21:32 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = -1;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[++i])
		if (haystack[i] == needle[0] &&
				(ft_strncmp(&haystack[i], needle, ft_strlen(needle))) == 0)
			return (&((char*)haystack)[i]);
	return (NULL);
}
