/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:48:21 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/16 18:48:22 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			solve_quadratic(t_iter *iter)
{
	float		discriminant;

	iter->t[0] = -1;
	iter->t[1] = -1;
	discriminant = iter->b * iter->b - 4 * iter->a * iter->c;
	if (discriminant == 0)
		iter->t[0] = -(iter->b / (2 * iter->a));
	else if (discriminant > 0)
	{
		iter->t[0] = ((-iter->b + sqrt(discriminant)) / (2 * iter->a));
		iter->t[1] = ((-iter->b - sqrt(discriminant)) / (2 * iter->a));
		if (iter->t[0] > iter->t[1])
			ft_fswap(&(iter->t[0]), &(iter->t[1]));
	}
}

int32_t			intersect_cap(t_object *object, t_iter *iter)
{
	t_object	enigma;
	t_plane		cap;
	int32_t		color;

	bzero(&enigma, sizeof(t_object));
	if (!(iter->m[0] > iter->cap_start && iter->m[0] < iter->cap_end)
			&& (iter->m[1] > iter->cap_start && iter->m[1] < iter->cap_end))
	{
		enigma.position = object->position;
		cap.normal = -iter->axis;
	}
	else if ((iter->m[0] > iter->cap_start && iter->m[0] < iter->cap_end)
			&& !(iter->m[1] > iter->cap_start && iter->m[1] < iter->cap_end))
	{
		enigma.position = object->position + scale(iter->cap_end, iter->axis);
		cap.normal = iter->axis;
	}
	enigma.color = object->color;
	enigma.curr = &cap;
	intersect_plane(&enigma, iter);
	color = iter->color;
	return (color);
}

int32_t			get_intersect_color(t_object *object, t_iter *iter)
{
	int32_t		color;

	color = -1;
	if ((iter->m[0] < iter->cap_start) && !(iter->m[1] < iter->cap_start))
		return (intersect_cap(object, iter));
	else if (iter->m[0] > iter->cap_start && iter->m[0] < iter->cap_end)
	{
		if (iter->t[0] < iter->cap_start)
			return (color);
		iter->hit_point = iter->ray.origin +
								scale(iter->t[0], iter->ray.direction);
		iter->hit_normal = normalize(iter->hit_point - (object->position +
								scale(iter->m[0], iter->axis)));
		color = object->color;
	}
	else if ((iter->m[0] > iter->cap_end) && !(iter->m[1] > iter->cap_end))
		return (intersect_cap(object, iter));
	return (color);
}
