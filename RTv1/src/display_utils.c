/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:51:57 by vrudyka           #+#    #+#             */
/*   Updated: 2019/07/01 18:51:58 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(t_edit *edit, int color, int x, int y)
{
	int			*pixel;
	SDL_Surface	*surface;

	surface = edit->sdl.surface;
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pixel = surface->pixels + y * surface->pitch +
				x * surface->format->BytesPerPixel;
		*pixel = color;
	}
}
