#include "fdf.h"

static double   percent(int start, int end, int current)
{
    double      placement;
    double      distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

static int      get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int             get_color(t_var *var, t_point start, t_point end)
{
    int         red;
    int         green;
    int         blue;
    double      percentage;

    if (var->color == end.color)
        return (var->color);
    if (var->dy < var->dx)
        percentage = percent(start.x, end.x, var->x);
    else
        percentage = percent(start.y, end.y, var->y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void			set_colors(t_var *var, int minZ, int maxZ)
{
	int			red;
	int			blue;
	int			green;
	double		per;

	int			y;
	int			x;

	var->colorMin = 0x27AEE3;
	var->colorMax = 0xFF66CC;

	y = -1;
	while (++y < var->height)
	{
		x = -1;
		while (++x < var->width)
		{
			per = percent(minZ, maxZ, var->map_r[y][x].z);
			red = get_light((var->colorMin >> 16) & 0xFF, (var->colorMax >> 16) & 0xFF, per);
    		green = get_light((var->colorMin >> 8) & 0xFF, (var->colorMax >> 8) & 0xFF, per);
			blue = get_light(var->colorMin & 0xFF, var->colorMax & 0xFF, per);
			var->map_r[y][x].color = var->map_o[y][x].color = ((red << 16) | (green << 8) | blue);
		}
	}
}