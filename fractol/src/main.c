/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:09:16 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 10:44:14 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_defaults(t_var *var, double mx, double my, double zoom)
{
	var->movex = mx;
	var->movey = my;
	var->zoom = zoom;
}

void			var_set(t_var *var, char c)
{
	var->set = c;
	if (c == 'm')
		set_defaults(var, -0.75, 0, 0.95);
	else if (c == 'j')
	{
		var->cre = 0.285;
		var->cim = 0.01;
		set_defaults(var, 0, 0, 1);
	}
	else if (c == 'b')
		set_defaults(var, -0.45, -0.5, 0.85);
}

int				main(int ac, char **av)
{
	t_var		*var;

	if (ac != 2)
		terminate("usage ./fractol [type]\n > Mandelbrot\n > Julia\n > Ship");
	var = img_init(av[1]);
	if (!(ft_strcmp("Mandelbrot", av[1])))
		var_set(var, 'm');
	else if (!(ft_strcmp("Julia", av[1])))
		var_set(var, 'j');
	else if (!(ft_strcmp("Ship", av[1])))
		var_set(var, 'b');
	else
		terminate("Invalid Fractal");
	key_init(var);
	thread_init(var);
	return (0);
}
