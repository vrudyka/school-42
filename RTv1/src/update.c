/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:56:10 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/25 11:56:12 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			display_everything(t_edit *edit)
{
	generate_image(edit);
}

void			mousebuttondown(t_edit *edit, SDL_Event event)
{
	click_on(edit, event.motion.x, event.motion.y);
}

void			keydown(t_edit *edit, SDL_Event event)
{
	if (edit->to_edit != NULL)
	{
		if (event.key.keysym.sym == SDLK_RIGHT)
			edit->to_edit->position[X] += 0.15;
		else if (event.key.keysym.sym == SDLK_LEFT)
			edit->to_edit->position[X] -= 0.15;
		else if (event.key.keysym.sym == SDLK_DOWN)
			edit->to_edit->position[Y] += 0.15;
		else if (event.key.keysym.sym == SDLK_UP)
			edit->to_edit->position[Y] -= 0.15;
		else if (event.key.keysym.sym == SDLK_EQUALS)
			edit->to_edit->position[Z] += 0.15;
		else if (event.key.keysym.sym == SDLK_MINUS)
			edit->to_edit->position[Z] -= 0.15;
	}
}

void			update(t_edit *edit)
{
	t_sdl		*sdl;

	sdl = &(edit->sdl);
	while (1)
	{
		SDL_FillRect(sdl->surface, NULL, 0x000000);
		while (SDL_PollEvent(&(sdl->event)))
		{
			if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
				mousebuttondown(edit, sdl->event);
			if (sdl->event.type == SDL_KEYDOWN)
				keydown(edit, sdl->event);
			if (sdl->event.type == SDL_QUIT ||
					(sdl->event.type == SDL_KEYDOWN &&
					sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				return ;
		}
		display_everything(edit);
		SDL_UpdateWindowSurface(sdl->win);
	}
}
