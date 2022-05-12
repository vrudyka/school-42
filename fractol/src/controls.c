/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:38:05 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 10:44:04 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_press(int butt, int x, int y, t_var *var)
{
	x = 0;
	y = 0;
	if (butt == 4)
		var->zoom *= 1.05;
	else if (butt == 5)
		var->zoom /= 1.05;
	update(var);
	return (0);
}

int				mouse_move(int x, int y, t_var *var)
{
	if (var->set == 'j' && (x >= 0 && x < WIN_W) && (y >= 0 && y < WIN_H) && var->pause == 0)
	{
		var->cim = (((double)x * 2) / WIN_W) - 1;
		var->cre = (((double)y * 2) / WIN_H) - 1;
	}
	update(var);
	return (0);
}

int				key_down(int key, t_var *var)
{
	if (key == ESC)
		exit(0);
	else if (key == LEFT)
		var->movex += 0.05 / var->zoom;
	else if (key == RIGHT)
		var->movex -= 0.05 / var->zoom;
	else if (key == DOWN)
		var->movey += 0.05 / var->zoom;
	else if (key == UP)
		var->movey -= 0.05 / var->zoom;
	else if (key == Q)
		var->maxI += 20;
	else if (key == A)
		var->maxI -= 20;
	else if (key == 49)
		var->pause = var->pause == 0 ? 1 : 0;
	update(var);
	return (0);
}
