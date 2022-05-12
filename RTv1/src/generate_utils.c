/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:31:20 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/10 19:31:21 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			initialize_cam_matrix(t_edit *edit)
{
	t_vector random;

	random = (t_vector){0.0, 1.0, 0.0};
	edit->c2w.look_at = normalize(edit->scene.camera.direction -
								edit->scene.camera.position);
	edit->c2w.right = normalize(cross(edit->c2w.look_at, random));
	edit->c2w.up = cross(edit->c2w.look_at, edit->c2w.right);
}

t_vector		c2w_transform(int t_x, int t_y, t_matrix c2w)
{
	t_vector	v;
	float		x;
	float		y;

	y = (WIN_H - t_y * 2.0) / WIN_W;
	x = (WIN_W - t_x * 2.0) / WIN_W;
	v[X] = x * c2w.right[X] + y * c2w.up[X] + 2.0 * c2w.look_at[X];
	v[Y] = x * c2w.right[Y] + y * c2w.up[Y] + 2.0 * c2w.look_at[Y];
	v[Z] = x * c2w.right[Z] + y * c2w.up[Z] + 2.0 * c2w.look_at[Z];
	v = normalize(v);
	return (v);
}
