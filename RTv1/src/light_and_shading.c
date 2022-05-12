/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:41:35 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/04 10:41:37 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int32_t			get_color(float intensity, int32_t obj_color)
{
	int8_t		r;
	int8_t		g;
	int8_t		b;

	r = ((obj_color >> 16) & 0xFF) * intensity;
	g = ((obj_color >> 8) & 0xFF) * intensity;
	b = (obj_color & 0xFF) * intensity;
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void			get_angle_dist(t_edit *edit, t_iter *iter, t_light *light)
{
	iter->angle = dot(edit->hit.hit_normal,
						normalize(light->position - light->direction));
	if (iter->angle < 0.0)
		iter->angle = 0.0;
	iter->dist_light = vector_length(light->position - edit->hit.hit_point)
						* DAMPING;
	iter->dist_cam = vector_length(edit->scene.camera.position -
						edit->hit.hit_point);
}

int32_t			mix_light(t_edit *edit, t_iter iter)
{
	t_light		*light;
	int32_t		color;
	float		intensity;
	float		max_intensity;

	max_intensity = 0.0;
	light = edit->scene.lights;
	while (light)
	{
		get_angle_dist(edit, &iter, light);
		intensity = (light->intensity * iter.angle) /
							((iter.dist_cam * iter.dist_light) * 17.5);
		if (intensity > 1.0)
			intensity = 1.0;
		else if (intensity < 0.0)
			intensity = 0.0;
		if (intensity > max_intensity)
			max_intensity = intensity;
		light = light->next;
	}
	color = get_color(max_intensity, edit->hit.color);
	return (color);
}
