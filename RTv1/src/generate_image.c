/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:14:30 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/26 13:14:31 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int8_t			trace_ray(t_edit *edit, t_iter *iter)
{
	t_object	*object;
	float		dist;
	float		min_dist;

	min_dist = INT_MAX;
	edit->hit.color = -1;
	object = edit->scene.objects;
	while (object != NULL)
	{
		edit->intersect[object->type](object, iter);
		if (iter->color != -1)
		{
			dist = vector_length(iter->ray.origin - iter->hit_point);
			if (dist < min_dist && dist != 0)
			{
				edit->hit.color = iter->color;
				edit->hit.hit_point = iter->hit_point;
				edit->hit.hit_normal = iter->hit_normal;
				edit->hit.object = object;
				min_dist = dist;
			}
		}
		object = object->next;
	}
	return (edit->hit.color != -1 ? 1 : 0);
}

void			check_lights(t_edit *edit, t_iter iter, int32_t *color)
{
	t_light		*light;
	t_vector	light_pos;

	light = edit->scene.lights;
	while (light)
	{
		light_pos = light->position;
		iter.ray.direction = normalize(light_pos - edit->hit.hit_point);
		if (trace_ray(edit, &iter))
		{
			*color = 0x000000;
			break ;
		}
		light = light->next;
	}
}

int32_t			get_pixel_color(t_edit *edit, t_iter iter)
{
	int32_t		color;

	iter.ray.origin = edit->scene.camera.position;
	iter.ray.direction = c2w_transform(iter.x, iter.y, edit->c2w);
	if (trace_ray(edit, &iter))
	{
		iter.ray.origin = edit->hit.hit_point;
		color = mix_light(edit, iter);
		check_lights(edit, iter, &color);
	}
	else
		color = 0x000000;
	return (color);
}

void			generate_image(t_edit *edit)
{
	t_iter		iter;
	int32_t		color;

	initialize_cam_matrix(edit);
	iter.y = -1;
	while (++iter.y != WIN_H)
	{
		iter.x = -1;
		while (++iter.x != WIN_W)
		{
			color = get_pixel_color(edit, iter);
			put_pixel(edit, color, iter.x, iter.y);
		}
	}
}
