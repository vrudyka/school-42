/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:52:37 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/15 16:38:19 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_empty(void)
{
	char	*res;

	res = (char*)malloc(sizeof(char));
	res[0] = '\0';
	return (res);
}

static char	*ft_fill(char const *s, size_t i, size_t len, char *res)
{
	size_t	k;

	k = 0;
	while (i < len)
	{
		res[k] = s[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (if_empty());
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if (!(res = ft_memalloc(len - i + 1)))
		return (NULL);
	return (ft_fill(s, i, len, res));
}
