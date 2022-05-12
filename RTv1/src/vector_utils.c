/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:07:57 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/01 14:07:58 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		scale(float multiplier, t_vector v)
{
	t_vector	product;

	product[X] = multiplier * v[X];
	product[Y] = multiplier * v[Y];
	product[Z] = multiplier * v[Z];
	return (product);
}

t_vector		cross(t_vector v1, t_vector v2)
{
	t_vector	product;

	product[X] = v1[Y] * v2[Z] - v1[Z] * v2[Y];
	product[Y] = v1[Z] * v2[X] - v1[X] * v2[Z];
	product[Z] = v1[X] * v2[Y] - v1[Y] * v2[X];
	return (product);
}

float			vector_length(t_vector v)
{
	float		length;

	length = sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]);
	return (length);
}

t_vector		normalize(t_vector v)
{
	t_vector	normalized;
	float		length;

	length = sqrt((v[X] * v[X]) + (v[Y] * v[Y]) + (v[Z] * v[Z]));
	normalized[X] = v[X] / length;
	normalized[Y] = v[Y] / length;
	normalized[Z] = v[Z] / length;
	return (normalized);
}

float			dot(t_vector v1, t_vector v2)
{
	float		product;

	product = v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z];
	return (product);
}
