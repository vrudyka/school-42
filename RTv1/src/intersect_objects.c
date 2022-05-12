/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:23:15 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/01 21:23:17 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			intersect_sphere(t_object *object, t_iter *iter)
{
	t_sphere	*sphere;

	iter->color = -1;
	sphere = (t_sphere *)(object->curr);
	iter->diff = iter->ray.origin - object->position;
	iter->a = dot(iter->ray.direction, iter->ray.direction);
	iter->b = 2 * dot(iter->ray.direction, iter->diff);
	iter->c = dot(iter->diff, iter->diff) - sphere->radius;
	solve_quadratic(iter);
	if (iter->t[0] > 0.01)
	{
		iter->hit_point = iter->ray.origin +
								scale(iter->t[0], iter->ray.direction);
		iter->hit_normal = normalize(iter->hit_point - object->position);
		iter->color = object->color;
	}
}

void			intersect_plane(t_object *object, t_iter *iter)
{
	t_plane		*plane;
	float		diff;
	float		angle;

	iter->color = -1;
	plane = (t_plane *)(object->curr);
	angle = dot(iter->ray.direction, plane->normal);
	if (angle != 0)
	{
		diff = dot(iter->ray.origin - object->position, plane->normal);
		if (SIGN(angle) != SIGN(diff))
		{
			iter->t[0] = -diff / angle;
			if (iter->t[0] > 0.01)
			{
				iter->hit_point = iter->ray.origin +
										scale(iter->t[0], iter->ray.direction);
				iter->hit_normal = angle < 0 ? plane->normal : -plane->normal;
				iter->color = object->color;
			}
		}
	}
}

void			intersect_cylinder(t_object *object, t_iter *iter)
{
	t_cylinder	*cylinder;
	float		angle;
	float		diff;

	iter->color = -1;
	cylinder = (t_cylinder *)(object->curr);
	iter->diff = iter->ray.origin - object->position;
	angle = dot(iter->ray.direction, cylinder->axis);
	diff = dot(iter->diff, cylinder->axis);
	iter->a = dot(iter->ray.direction, iter->ray.direction) - (angle * angle);
	iter->b = 2 * (dot(iter->ray.direction, iter->diff) - (angle * diff));
	iter->c = dot(iter->diff, iter->diff) - (diff * diff) -
					(cylinder->radius * cylinder->radius);
	solve_quadratic(iter);
	if (iter->t[0] > 0.01 && iter->t[1] > 0)
	{
		iter->m[0] = angle * iter->t[0] + diff;
		iter->m[1] = angle * iter->t[1] + diff;
		iter->cap_start = 0;
		iter->cap_end = cylinder->end;
		iter->axis = cylinder->axis;
		iter->color = get_intersect_color(object, iter);
	}
}

void			intersect_cone(t_object *object, t_iter *iter)
{
	t_cone		*cone;
	float		k;
	float		angle;
	float		diff;

	iter->color = -1;
	cone = (t_cone *)(object->curr);
	iter->diff = iter->ray.origin - object->position;
	k = 1 + (cone->angle * cone->angle);
	angle = dot(iter->ray.direction, cone->axis);
	diff = dot(iter->diff, cone->axis);
	iter->a = dot(iter->ray.direction, iter->ray.direction) -
					(k * (angle * angle));
	iter->b = 2 * (dot(iter->ray.direction, iter->diff) - (k * (angle * diff)));
	iter->c = dot(iter->diff, iter->diff) - (k * (diff * diff));
	solve_quadratic(iter);
	if (iter->t[0] > 0.01 && iter->t[1] > 0)
	{
		iter->m[0] = angle * iter->t[0] + diff;
		iter->m[1] = angle * iter->t[1] + diff;
		iter->cap_start = cone->start;
		iter->cap_end = cone->end;
		iter->axis = cone->axis;
		iter->color = get_intersect_color(object, iter);
	}
}
