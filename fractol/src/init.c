/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:23:18 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 10:44:09 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				update(t_var *var)
{
	t_img		*img;

	img = var->img;
	ft_bzero(img->addr, WIN_W * WIN_H * 4);
	thread_init(var);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->ptr, 0, 0);
	return (0);
}

void			thread_init(t_var *var)
{
	t_var		tmp[THREAD];
	int			i;

	i = -1;
	while (++i < THREAD)
	{
		tmp[i] = *var;
		tmp[i].xstart = 0;
		tmp[i].xend = WIN_W;
		tmp[i].ystart = WIN_H / THREAD * i;
		tmp[i].yend = WIN_H / THREAD * (i + 1);
		pthread_create(&var->threads[i], NULL, (void *)calc, (void *)&tmp[i]);
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(var->threads[i], NULL);
}

void			key_init(t_var *var)
{
	t_img		*img;

	img = var->img;
	mlx_expose_hook(img->mlx_win, update, var);
	mlx_hook(img->mlx_win, 4, 1L << 2, mouse_press, var);
	mlx_hook(img->mlx_win, 6, 1L << 6, mouse_move, var);
	mlx_hook(img->mlx_win, 2, 5, key_down, var);
	mlx_hook(img->mlx_win, 17, X_MASK, kaput, var);
	mlx_do_sync(img->mlx_ptr);
	mlx_loop(img->mlx_ptr);
}

t_var			*img_init(char *str)
{
	t_var		*var;
	t_img		*img;

	var = (t_var *)malloc(sizeof(t_var));
	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_W, WIN_H, str);
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size_line, &img->endian);
	var->img = img;
	var->maxI = 100;
	var->pause = 0;
	return (var);
}
