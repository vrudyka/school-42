/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:50:53 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/25 14:50:55 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_camera(t_edit *edit, int fd, char *line, int i)
{
	int			ret;

	while (++i < CAM_PARAM && (ret = get_next_line(fd, &line)))
	{
		if (ret > 0 && ft_strstr(line, "pos: "))
			edit->scene.camera.position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "dir: "))
			edit->scene.camera.direction = get_vector(line);
		else
			terminate("Invalid camera parameter");
		free(line);
	}
}

void			parse_light(t_edit *edit, int fd, char *line, int i)
{
	int			ret;
	t_light		*light;

	if (!(light = (t_light *)ft_memalloc(sizeof(t_light))))
		terminate("No memory :(");
	while (++i < LIG_PARAM && (ret = get_next_line(fd, &line)))
	{
		if (ret > 0 && ft_strstr(line, "pos: "))
			light->position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "dir: "))
			light->direction = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "int: "))
			light->intensity = get_float(line);
		else
			terminate("Invalid light parameter");
		free(line);
	}
	add_last_light(&(edit->scene), light);
	if (light->intensity < 0 || light->intensity > 1)
		terminate("Light intensity range is 0.0 - 1.0");
}

void			parse_object(t_edit *edit, int fd, int to_parse)
{
	t_object	*object;
	char		*line;

	line = NULL;
	object = get_last_object(&(edit->scene), to_parse);
	edit->to_parse = object;
	if (to_parse == SPHERE)
		object->curr = parse_sphere(edit, fd, line, -1);
	else if (to_parse == PLANE)
		object->curr = parse_plane(edit, fd, line, -1);
	else if (to_parse == CYLINDER)
		object->curr = parse_cylinder(edit, fd, line, -1);
	else if (to_parse == CONE)
		object->curr = parse_cone(edit, fd, line, -1);
}

void			parse_scene(t_edit *edit, int fd)
{
	int			ret;
	char		*line;

	ft_bzero(&(edit->scene), sizeof(t_scene));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strcmp("cam:", line) == 0)
			parse_camera(edit, fd, line, -1);
		else if (ft_strcmp("light:", line) == 0)
			parse_light(edit, fd, line, -1);
		else if (ft_strcmp("sphere:", line) == 0)
			parse_object(edit, fd, SPHERE);
		else if (ft_strcmp("plane:", line) == 0)
			parse_object(edit, fd, PLANE);
		else if (ft_strcmp("cylinder:", line) == 0)
			parse_object(edit, fd, CYLINDER);
		else if (ft_strcmp("cone:", line) == 0)
			parse_object(edit, fd, CONE);
		free(line);
	}
}
