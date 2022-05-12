#include "fdf.h"

static void	rotate_axis(t_point *map_r, t_point map, t_rot **rot)
{
	double		y;
	double		z;
	double		x;

	if (map.z > 0)
		map.color = 0xFF66CC;
	else
		map.color = 0x27AEE3;
	y = map.y;
	z = map.z;
	map.y = (y * cos((*rot)->x)) + (z * sin((*rot)->x));
	map.z = -(y * sin((*rot)->x)) + (z * cos((*rot)->x));
	x = map.x;
	z = map.z;
	map.x = (x * cos((*rot)->y)) + (z * sin((*rot)->y));
	map.z = -(x * sin((*rot)->y)) + (z * cos((*rot)->y));
	x = map.x;
	y = map.y;
	map.x = (x * cos((*rot)->z)) - (y * sin((*rot)->z));
	map.y = (x * sin((*rot)->z)) + (y * cos((*rot)->z));
	(*map_r).x = map.x;
	(*map_r).y = map.y;
	(*map_r).z = map.z;
}

static void		increment_axis(char axis, t_rot **rot)
{
	if (axis == 'x')
		(*rot)->x += TURN_A;
	else if (axis == 'y')
		(*rot)->y += TURN_A;
	else if (axis == 'z')
		(*rot)->z += TURN_A;
	else if (axis == 'c')
		(*rot)->x -= TURN_A;
	else if (axis == 'u')
		(*rot)->y -= TURN_A;
	else if (axis == 'a')
		(*rot)->z -= TURN_A;
}

void			rotate(t_var *var, char axis, t_rot **rot)
{
	int			y;
	int			x;
	t_point		**map_o;
	t_point		**map_r;

	y = -1;
	map_o = var->map_o;
	map_r = var->map_r;
	increment_axis(axis, rot);
	while (++y < var->height)
	{
		x = -1;
		while (++x < var->width)
			rotate_axis(&(map_r[y][x]), map_o[y][x], rot);
	}
}

void			iso(t_var *var)
{
	int			y;
	int			x;
	t_point		**map_o;

	y = -1;
	map_o = var->map_o;
	while (++y < var->height)
	{
		x = -1;
		while (++x < var->width)
		{
			var->map_r[y][x].x = (map_o[y][x].x - map_o[y][x].y) * cos(0.523599);
			var->map_r[y][x].y = -(map_o[y][x].z) + (map_o[y][x].x + map_o[y][x].y) * sin(0.523599);
		}
	}
}
