#include "fdf.h"

static void		key_num(int key, t_var *var, t_rot **rot)
{
	if (key == NUM_2)
		rotate(var, 'x', rot);
	else if (key == NUM_6)
		rotate(var, 'y', rot);
	else if (key == NUM_9)
		rotate(var, 'z', rot);
	else if (key == NUM_8)
		rotate(var, 'c', rot);
	else if (key == NUM_4)
		rotate(var, 'u', rot);
	else if (key == NUM_7)
		rotate(var, 'a', rot);
}

int				key_down(int key, t_var *var)
{
	static t_rot	*rot;

	if (rot == NULL)
	{
		rot = malloc(sizeof(t_rot));
		rot->x = 0.0;
		rot->y = 0.0;
		rot->z = 0.0;
	}
	if (key == ESC)
		exit(0);
	else if (key == NUM_2 || key == NUM_4 || key == NUM_6 ||
			key == NUM_7 || key == NUM_8 || key == NUM_9)
		key_num(key, var, &rot);
	else if (key == MAIN_KEY_I)
		iso(var);
	update(var);
	return (0);
}
