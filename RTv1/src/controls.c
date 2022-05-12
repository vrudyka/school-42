/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:01:00 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/10 17:01:02 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			click_on(t_edit *edit, int x, int y)
{
	t_iter		iter;

	iter.ray.origin = edit->scene.camera.position;
	iter.ray.direction = c2w_transform(x, y, edit->c2w);
	if (trace_ray(edit, &iter))
		edit->to_edit = edit->hit.object;
	else
		edit->to_edit = NULL;
}
