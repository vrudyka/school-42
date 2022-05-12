/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:19:49 by vrudyka           #+#    #+#             */
/*   Updated: 2019/02/18 14:45:11 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ESC		53
# define LEFT		86
# define RIGHT		88
# define DOWN		84
# define UP			91
# define Q			12
# define A			0
# define SPACE		49

# define WIN_W		1680
# define WIN_H		1080

# define X_MASK		0

# define THREAD		8

# include <libft.h>
# include <pthread.h>
# include "mlx.h"
# include "math.h"

typedef	struct		s_img
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct		s_var
{
	pthread_t		threads[THREAD];
	t_img			*img;
	int				pause;
	int				maxI;
	char			set;
	int				xstart;
	int				xend;
	int				ystart;
	int				yend;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
}					t_var;

int					update(t_var *var);

void				key_init(t_var *var);

void				thread_init(t_var *var);

t_var				*img_init(char *str);

void				*calc(t_var *var);

t_color				*palette(int i, int maxI);

t_color				*hsv_to_rgb(int r, int g, int b);

void				pixel_put(t_img *img, t_color *color, int x, int y);

int					mouse_press(int butt, int x, int y, t_var *var);

int					mouse_move(int x, int y, t_var *var);

int					key_down(int key, t_var *var);

void				terminate(char *str);

int					kaput(void *param);

#endif
