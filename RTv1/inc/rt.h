/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:11:08 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/25 12:11:09 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIN_H		720
# define WIN_W		1280

# define INT_MAX	2147483647
# define DAMPING	0.001

# define TYPES		4
# define CAM_PARAM	2
# define LIG_PARAM	3
# define SPH_PARAM	3
# define PLN_PARAM	3
# define CYL_PARAM	6

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2
# define CONE		3

# define X			0
# define Y			1
# define Z			2

# include <libft.h>
# include <SDL.h>
# include <math.h>
# include <fcntl.h>

# include <stdio.h> //rm

typedef float		t_vector __attribute__((vector_size(sizeof(float)*3)));

typedef enum		e_type
{
	sphere_ty,
	cylinder_ty,
	plane_ty,
	cone_ty
}					t_type;

typedef struct		s_chan
{
	float			r;
	float			g;
	float			b;
}					t_chan;

typedef struct		s_sdl
{
	SDL_Event		event;
	SDL_Window		*win;
	SDL_Surface		*surface;
}					t_sdl;

typedef struct		s_camera
{
	t_vector		position;
	t_vector		direction;
}					t_camera;

typedef struct		s_sphere
{
	float			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		normal;
}					t_plane;

typedef struct		s_cylinder
{
	t_vector		axis;
	float			radius;
	float			end;
}					t_cylinder;

typedef struct		s_cone
{
	t_vector		axis;
	float			angle;
	float			start;
	float			end;
}					t_cone;

typedef struct		s_object
{
	t_vector		position;
	int32_t			color;
	t_type			type;
	void			*curr;
	struct s_object	*next;
}					t_object;

typedef struct		s_light
{
	t_vector		position;
	t_vector		direction;
	float			intensity;
	struct s_light	*next;
}					t_light;

typedef struct		s_scene
{
	t_camera		camera;
	t_object		*objects;
	t_light			*lights;
	int32_t			num_of_objects;
}					t_scene;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;

typedef struct		s_matrix
{
	t_vector		look_at;
	t_vector		right;
	t_vector		up;
}					t_matrix;

typedef struct		s_hit
{
	t_vector		hit_point;
	t_vector		hit_normal;
	t_object		*object;
	int32_t			color;
}					t_hit;

typedef struct		s_iter
{
	t_ray			ray;
	t_vector		axis;
	t_vector		hit_point;
	t_vector		hit_normal;
	t_vector		diff;
	t_hit			*hit;
	float			t[2];
	float			m[2];
	int32_t			x;
	int32_t			y;
	float			a;
	float			b;
	float			c;
	float			angle;
	float			dist_light;
	float			dist_cam;
	float			intensity;
	float			cap_start;
	float			cap_end;
	float			cam_x;
	float			cam_y;
	int32_t			color;
}					t_iter;

typedef struct		s_edit
{
	t_sdl			sdl;
	t_scene			scene;
	t_matrix		c2w;
	t_hit			hit;
	t_object		*to_edit;
	t_object		*to_parse;
	void			(*intersect[TYPES])(t_object *object, t_iter *iter);
}					t_edit;

t_sphere			*parse_sphere(t_edit *edit, int fd, char *line, int i);

t_plane				*parse_plane(t_edit *edit, int fd, char *line, int i);

t_cylinder			*parse_cylinder(t_edit *edit, int fd, char *line, int i);

t_cone				*parse_cone(t_edit *edit, int fd, char *line, int i);

void				parse_scene(t_edit *edit, int fd);

t_vector			get_vector(char *line);

int32_t				get_int(char *line, int base);

float				get_float(char *line);

t_object			*get_last_object(t_scene *scene, t_type type);

void				add_last_light(t_scene *scene, t_light *light);

int32_t				mix_light(t_edit *edit, t_iter iter);

void				solve_quadratic(t_iter *iter);

int32_t				get_intersect_color(t_object *object, t_iter *iter);

void				intersect_sphere(t_object *object, t_iter *iter);

void				intersect_plane(t_object *object, t_iter *iter);

void				intersect_cylinder(t_object *object, t_iter *iter);

void				intersect_cone(t_object *object, t_iter *iter);

t_vector			scale(float multiplier, t_vector v);

t_vector			cross(t_vector v1, t_vector v2);

float				vector_length(t_vector v);

t_vector			normalize(t_vector v);

float				dot(t_vector v1, t_vector v2);

void				click_on(t_edit *edit, int x, int y);

void				initialize_cam_matrix(t_edit *edit);

t_vector			c2w_transform(int t_x, int t_y, t_matrix c2w);

int8_t				trace_ray(t_edit *edit, t_iter *iter);

void				generate_image(t_edit *edit);

void				update(t_edit *edit);

void				put_pixel(t_edit *edit, int color, int x, int y);

void				terminate(char *error);

#endif
