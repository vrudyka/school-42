/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:09:37 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/25 12:09:38 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			terminate(char *error)
{
	ft_putendl(error);
	exit(0);
}

int32_t			initialize_sdl(t_edit *edit, char *param)
{
	SDL_Surface	*icon;
	char		*title;

	param[0] = ft_toupper(param[0]);
	title = ft_strjoin("RTv1 ", param);
	SDL_Init(SDL_INIT_EVERYTHING);
	edit->sdl.win = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIN_W,
			WIN_H,
			SDL_WINDOW_ALLOW_HIGHDPI);
	edit->sdl.surface = SDL_GetWindowSurface(edit->sdl.win);
	edit->to_edit = NULL;
	if ((icon = SDL_LoadBMP("./icon.bmp")) == NULL)
		terminate("Missing icon");
	SDL_SetWindowIcon(edit->sdl.win, icon);
	SDL_FreeSurface(icon);
	free(title);
	return (0);
}

int32_t			main(int32_t ac, char **av)
{
	t_edit		edit;
	char		*path;
	int32_t		fd;

	if (ac == 2)
	{
		path = ft_strjoin("./scenes/", av[1]);
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			terminate("Could not read file");
		edit.intersect[SPHERE] = intersect_sphere;
		edit.intersect[PLANE] = intersect_plane;
		edit.intersect[CYLINDER] = intersect_cylinder;
		edit.intersect[CONE] = intersect_cone;
		parse_scene(&edit, fd);
		initialize_sdl(&edit, av[1]);
		update(&edit);
	}
	else
		terminate("usage: ./RTv1 [scene name]");
	SDL_DestroyWindow(edit.sdl.win);
	SDL_Quit();
	return (0);
}
