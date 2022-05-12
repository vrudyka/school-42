/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:31:06 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/18 16:58:08 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while ((s1[i] == s2[i]) && (i < (int)n) && s1[i] && s2[i])
		i++;
	if (i != (int)n)
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (((unsigned char*)s1)[i - 1] - ((unsigned char*)s2)[i - 1]);
}
