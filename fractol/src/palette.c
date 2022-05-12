/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:19:05 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 14:44:38 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline t_color	*hsv_to_rgb(int r, int g, int b)
{
	t_color		*color;

	color = (t_color *)malloc(sizeof(t_color));
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_color			*palette(int i, int maxI)
{
	int			r;
	int			g;
	int			b;
	double		t;
	t_color		*color;

	if (i == maxI)
		color = hsv_to_rgb(22, 0, 22);
	else
	{
		t = ((double)i / (double)maxI);
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color = hsv_to_rgb(r, g, b);
	}
	return (color);
}