/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:39:49 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/11 11:25:29 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_len(char const *s, char c)
{
	size_t		i;
	size_t		wlen;

	i = 0;
	wlen = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			wlen++;
		}
		if (s[i] == c && s[i] != '\0')
			i++;
	}
	return (wlen);
}

static char		**ft_fill(char const *s, char c, char **res, size_t wlen)
{
	size_t		i;
	size_t		nu;
	size_t		nu_i;

	i = 0;
	nu = 0;
	nu_i = 0;
	while (s[i] != '\0' && nu < wlen)
	{
		nu_i = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				res[nu][nu_i] = s[i];
				nu_i++;
				i++;
			}
			res[nu][nu_i] = '\0';
			nu++;
		}
		i++;
	}
	res[wlen] = NULL;
	return (res);
}

static char		**ft_mem(char const *s, char c, char **res, size_t wlen)
{
	size_t		i;
	size_t		nu;
	size_t		nu_i;

	i = 0;
	nu = 0;
	nu_i = 0;
	while (s[i] != '\0' && nu_i < wlen)
	{
		if (s[i] != c)
		{
			nu = 0;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				nu++;
			}
			if (!(res[nu_i] = (char*)malloc(sizeof(char) * (nu + 1))))
				return (NULL);
			nu_i++;
		}
		i++;
	}
	return (ft_fill(s, c, res, wlen));
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		wlen;
	char		**res;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
	{
		if (!(res = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		if (!(res[0] = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	wlen = ft_w_len(s, c);
	if (wlen == 0 || !(res = (char**)malloc(sizeof(char*) * (wlen + 1))))
		return (NULL);
	return (ft_mem(s, c, res, wlen));
}
