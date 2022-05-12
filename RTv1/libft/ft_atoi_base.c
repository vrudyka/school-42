/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:37:24 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/01 20:37:26 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_num(const char *str, int base)
{
	int				nbr;

	while ((*str >= '0' && *str <= '9') ||
			(*str >= 'A' && *str <= 'F') ||
			(*str >= 'a' && *str <= 'f'))
	{
		if (*str >= 'A' && *str <= 'F')
			nbr = (nbr * base) + (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'f')
			nbr = (nbr * base) + (*str - 'a' + 10);
		else
			nbr = (nbr * base) + (*str - '0');
		str++;
	}
	return (nbr);
}

int					ft_atoi_base(const char *str, int base)
{
	int					check;
	unsigned long int	nbr;

	check = 0;
	nbr = 0;
	if (!(base >= 2 && base <= 16))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			check = 1;
		str++;
	}
	while (*str == '0' || *str == 'x')
		str++;
	nbr = get_num(str, base);
	return (check ? -nbr : nbr);
}
