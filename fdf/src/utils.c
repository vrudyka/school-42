#include "fdf.h"

int				update(t_var *var)
{
	t_img		*img;

	img = var->img;
	ft_bzero(img->addr, WIN_WIDTH * WIN_HEIGHT * 4);
	display(var);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->ptr, 0, 0);
	return (0);
}

void			s_max(t_var *var)
{
	if (var->height < var->width)
		var->s_max = WIN_HEIGHT / (var->height + 4);
	else
		var->s_max = WIN_WIDTH / (var->width + 4);
	if (var->s_max > 48)
		var->s_max = 48;
}

int				termin(void *param)
{
	(void)param;
	exit(0);
}

int				terminate(char *str)
{
	ft_putendl(str);
	exit(0);
}


// void			free_map(t_point **map, t_var *var)
// {
// 	int			y;

// 	y = -1;
// 	while (++y < var->height)
// 	{
// 		free(map[y]);
// 	}
// 	free(map);
// }
