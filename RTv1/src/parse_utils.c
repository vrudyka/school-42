/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:30:11 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/25 17:30:12 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char		*skip_to(char *line, char to)
{
	char		*str;

	str = line;
	if (ft_isdigit(*str))
		str++;
	while (*str != to)
		str++;
	str++;
	return (str);
}

int32_t			get_int(char *line, int base)
{
	int32_t		result;
	char		*str;

	str = skip_to(line, ' ');
	result = ft_atoi_base(str, base);
	return (result);
}

float			get_float(char *line)
{
	float		result;
	char		*str;

	str = skip_to(line, ' ');
	result = ft_atof(str);
	return (result);
}

t_vector		get_vector(char *line)
{
	double		x;
	double		y;
	double		z;
	char		*str;
	t_vector	vector;

	str = skip_to(line, ' ');
	x = ft_atof(str);
	str = skip_to(str, ' ');
	y = ft_atof(str);
	str = skip_to(str, ' ');
	z = ft_atof(str);
	vector = (t_vector){x, y, z};
	return (vector);
}
