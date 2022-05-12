/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:21:44 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/26 18:21:45 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere		*parse_sphere(t_edit *edit, int fd, char *line, int i)
{
	int			ret;
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)ft_memalloc(sizeof(t_sphere))))
		terminate("No memory :(");
	while (++i < SPH_PARAM && (ret = get_next_line(fd, &line)))
	{
		if (ret > 0 && ft_strstr(line, "pos: "))
			edit->to_parse->position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "rad: "))
			sphere->radius = get_float(line);
		else if (ret > 0 && ft_strstr(line, "col: "))
			edit->to_parse->color = get_int(line, 16);
		else
			terminate("Invalid sphere parameter");
		free(line);
	}
	return (sphere);
}

t_plane			*parse_plane(t_edit *edit, int fd, char *line, int i)
{
	int			ret;
	t_plane		*plane;

	if (!(plane = (t_plane *)ft_memalloc(sizeof(t_plane))))
		terminate("No memory :(");
	while (++i < PLN_PARAM && (ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		if (ret > 0 && ft_strstr(line, "pos: "))
			edit->to_parse->position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "nor: "))
			plane->normal = normalize(get_vector(line));
		else if (ret > 0 && ft_strstr(line, "col: "))
			edit->to_parse->color = get_int(line, 16);
		else
			terminate("Invalid plane parameter");
		free(line);
	}
	return (plane);
}

t_cylinder		*parse_cylinder(t_edit *edit, int fd, char *line, int i)
{
	int			ret;
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)ft_memalloc(sizeof(t_cylinder))))
		terminate("No memory :(");
	while (++i < CYL_PARAM && (ret = get_next_line(fd, &line)))
	{
		if (ret > 0 && ft_strstr(line, "pos: "))
			edit->to_parse->position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "axis: "))
			cylinder->axis = normalize(get_vector(line));
		else if (ret > 0 && ft_strstr(line, "rad: "))
			cylinder->radius = get_float(line);
		else if (ret > 0 && ft_strstr(line, "end: "))
			cylinder->end = get_float(line);
		else if (ret > 0 && ft_strstr(line, "col: "))
			edit->to_parse->color = get_int(line, 16);
		else
			terminate("Invalid cylinder parameter");
		free(line);
	}
	return (cylinder);
}

t_cone			*parse_cone(t_edit *edit, int fd, char *line, int i)
{
	int			ret;
	t_cone		*cone;

	if (!(cone = (t_cone *)ft_memalloc(sizeof(t_cone))))
		terminate("No memory :(");
	while (++i < CYL_PARAM && (ret = get_next_line(fd, &line)))
	{
		if (ret > 0 && ft_strstr(line, "pos: "))
			edit->to_parse->position = get_vector(line);
		else if (ret > 0 && ft_strstr(line, "axis: "))
			cone->axis = normalize(get_vector(line));
		else if (ret > 0 && ft_strstr(line, "angle: "))
			cone->angle = get_float(line);
		else if (ret > 0 && ft_strstr(line, "end: "))
			cone->end = get_float(line);
		else if (ret > 0 && ft_strstr(line, "start: "))
			cone->start = get_float(line);
		else if (ret > 0 && ft_strstr(line, "col: "))
			edit->to_parse->color = get_int(line, 16);
		else
			terminate("Invalid cone parameter");
		free(line);
	}
	return (cone);
}
