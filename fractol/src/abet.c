/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:19:09 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 10:43:53 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		pixel_put(t_img *img, t_color *color, int x, int y)
{
	int			i;

	if ((x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H))
	{
		i = (y * WIN_W) + x;
		((t_color *)img->addr)[i].r = color->r;
		((t_color *)img->addr)[i].g = color->g;
		((t_color *)img->addr)[i].b = color->b;
		((t_color *)img->addr)[i].a = 0;
	}
	free(color);
}

int				kaput(void *param)
{
	(void)param;
	exit(0);
}

void			terminate(char *str)
{
	ft_putendl(str);
	exit(0);
}
