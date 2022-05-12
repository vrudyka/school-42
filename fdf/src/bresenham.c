#include "fdf.h"

static void		pixel_put(t_img *img, t_var *var, int x, int y)
{
	int			i;

	x += var->scale_x;
	y += var->scale_y;
	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		i = (y * WIN_WIDTH) + x;
		((t_color *)img->addr)[i].r = (var->color >> 16) & 0xFF;
		((t_color *)img->addr)[i].g = (var->color >> 8) & 0xFF;
		((t_color *)img->addr)[i].b = (var->color) & 0xFF;
		((t_color *)img->addr)[i].a = 0;
	}
}

static void		dy_dx(t_img *img, t_var *var, t_point zero, t_point one)
{
	int			i;

	var->d = (var->dy << 1) - var->dx;
	var->d1 = var->dy << 1;
	var->d2 = (var->dy - var->dx) << 1;
	var->x = zero.x + var->sx;
	var->y = zero.y;
	i = 0;
	while (++i <= var->dx)
	{
		if (var->d > 0)
		{
			var->d += var->d2;
			var->y += var->sy;
		}
		else
			var->d += var->d1;
		var->color = get_color(var, zero, one);
		pixel_put(img, var, var->x, var->y);
		var->x += var->sx;
	}
}

static void		dx_dy(t_img *img, t_var *var, t_point zero, t_point one)
{
	int			i;

	var->d = (var->dx << 1) - var->dy;
	var->d1 = var->dx << 1;
	var->d2 = (var->dx - var->dy) << 1;
	var->y = zero.y + var->sy;
	var->x = zero.x;
	i = 0;
	while (++i <= var->dy)
	{
		if (var->d > 0)
		{
			var->d += var->d2;
			var->x += var->sx;
		}
		else
			var->d += var->d1;
		var->color = get_color(var, zero, one);
		pixel_put(img, var, var->x, var->y);
		var->y += var->sy;
	}
}

static void		line_draw(t_img *img, t_var *var, t_point zero, t_point one)
{
	var->dx = ABS((one.x - zero.x));
	var->dy = ABS((one.y - zero.y));
	var->sx = (one.x >= zero.x ? 1 : -1);
	var->sy = (one.y >= zero.y ? 1 : -1);
	if (var->dy <= var->dx)
		dy_dx(img, var, zero, one);
	else
		dx_dy(img, var, zero, one);
}

void			display(t_var *var)
{
	int			y;
	int			x;
	t_img		*img;
	t_point		**map;

	y = -1;
	img = var->img;
	map = var->map_r;
	while (++y < var->height)
	{
		x = -1;
		while (++x < var->width)
		{
			if (x + 1 != var->width)
				line_draw(img, var, map[y][x], map[y][x + 1]);
			if (y + 1 != var->height)
				line_draw(img, var, map[y][x], map[y + 1][x]);
		}
	}
}
