#include        "fdf.h"

void			key_init(t_var *var)
{
	t_img		*img;

	img = var->img;
	mlx_hook(img->mlx_win, 2, 5, key_down, var);
	mlx_hook(img->mlx_win, 17, X_MASK, termin, var);
	mlx_loop(img->mlx_ptr);
}

t_img           *init_img(char *str)
{
	t_img		*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, str);
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
	return (img);
}

t_var       	*init_var(int fd, char *str)
{
	int			move_x;
	int			move_y;
	t_var		*var;

	var = (t_var*)malloc(sizeof(t_var));
	parsing_line(var, parsing_fdf(fd, &var));
	var->img = init_img(str);
	move_x = ((((WIN_WIDTH / var->s_max) - var->width) * var->s_max) / 2) + ((WIN_WIDTH % var->s_max) / 2);
	move_y = ((((WIN_HEIGHT / var->s_max) - var->height) * var->s_max) / 2) + ((WIN_HEIGHT % var->s_max) / 2);
	var->scale_x = ((var->width * var->s_max) / 2) + move_x;
	var->scale_y = ((var->height * var->s_max) / 2) + move_y;
	return (var);
}