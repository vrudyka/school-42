/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:15:44 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/09 19:17:40 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return (&((char*)haystack)[0]);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] &&
				(ft_strncmp(&haystack[i], needle, ft_strlen(needle))) == 0 &&
				ft_strlen(needle) <= len - i)
			return (&((char*)haystack)[i]);
		i++;
	}
	return (NULL);
}
