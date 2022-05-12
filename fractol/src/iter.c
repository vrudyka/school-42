/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:22:38 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 14:46:31 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		b_iter(t_var *var, int x, int y)
{
	int			i;
	t_color		*color;

	i = -1;
	(*var).cre = (1.5 * (x - WIN_W / 2)) / (0.5 * var->zoom * WIN_W) + var->movex;
	(*var).cim = (y - WIN_H / 2) / (0.5 * var->zoom * WIN_H) + var->movey;
	(*var).newre = 0;
	(*var).newim = 0;
	while (++i < var->maxI)
	{
		(*var).oldre = (*var).newre;
		(*var).oldim = (*var).newim;
		(*var).newre = (*var).oldre * (*var).oldre - ((*var).oldim * (*var).oldim) + (*var).cre;
		(*var).newim = fabs(2 * (*var).oldre * (*var).oldim) + (*var).cim;
		if (((*var).newre * (*var).newre + (*var).newim * (*var).newim) > 4)
			break ;
	}
	color = palette(i, var->maxI);
	pixel_put(var->img, color, x, y);
}

static void		j_iter(t_var *var, int x, int y)
{
	int			i;
	t_color		*color;

	i = -1;
	(*var).newre = (1.5 * (x - WIN_W / 2)) / (0.5 * var->zoom * WIN_W) + var->movex;
	(*var).newim = (y - WIN_H / 2) / (0.5 * var->zoom * WIN_H) + var->movey;
	while (++i < var->maxI)
	{
		(*var).oldre = (*var).newre;
		(*var).oldim = (*var).newim;
		(*var).newre = (*var).oldre * (*var).oldre - (*var).oldim * (*var).oldim + (*var).cre;
		(*var).newim = 2 * (*var).oldre * (*var).oldim + (*var).cim;
		if (((*var).newre * (*var).newre + (*var).newim * (*var).newim) > 4)
			break ;
	}
	color = palette(i, var->maxI);
	pixel_put(var->img, color, x, y);
}

static void		m_iter(t_var *var, int x, int y)
{
	int			i;
	t_color		*color;

	i = -1;
	(*var).cre = (1.5 * (x - WIN_W / 2)) / (0.5 * var->zoom * WIN_W) + var->movex;
	(*var).cim = (y - WIN_H / 2) / (0.5 * var->zoom * WIN_H) + var->movey;
	(*var).newre = 0;
	(*var).newim = 0;
	while (++i < var->maxI)
	{
		(*var).oldre = (*var).newre;
		(*var).oldim = (*var).newim;
		(*var).newre = (*var).oldre * (*var).oldre - (*var).oldim * (*var).oldim + (*var).cre;
		(*var).newim = 2 * (*var).oldre * (*var).oldim + (*var).cim;
		if (((*var).newre * (*var).newre + (*var).newim * (*var).newim) > 4)
			break ;
	}
	color = palette(i, var->maxI);
	pixel_put(var->img, color, x, y);
}

void			*calc(t_var *var)
{
	void		(*iter)(t_var*, int, int);
	t_img		*img;

	img = var->img;
	if (var->set == 'm')
		iter = m_iter;
	else if (var->set == 'j')
		iter = j_iter;
	else if (var->set == 'b')
		iter = b_iter;
	while (var->ystart < var->yend)
	{
		var->xstart = 0;
		while (var->xstart < var->xend)
		{
			(*iter)(var, var->xstart, var->ystart);
			var->xstart++;
		}
		var->ystart++;
	}
	return (NULL);
}
