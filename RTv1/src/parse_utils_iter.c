/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_iter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:12:52 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/26 18:12:53 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			add_last_light(t_scene *scene, t_light *light)
{
	t_light		*it;

	it = scene->lights;
	if (scene->lights == NULL)
		scene->lights = light;
	else
	{
		while (it->next != NULL)
			it = it->next;
		it->next = light;
	}
}

t_object		*get_last_object(t_scene *scene, t_type type)
{
	t_object	*it;
	t_object	*new;

	it = scene->objects;
	if (!(new = (t_object *)ft_memalloc(sizeof(t_object))))
		terminate("No memory :(");
	new->type = type;
	if (scene->objects == NULL)
	{
		scene->objects = new;
		return (scene->objects);
	}
	while (it->next != NULL)
		it = it->next;
	it->next = new;
	return (it->next);
}
