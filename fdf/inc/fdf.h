#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <fcntl.h>
# include "mlx.h"
# include "math.h"

# include <stdio.h>

# define WIN_HEIGHT	729
# define WIN_WIDTH	1280
# define TURN_A		0.1125
# define X_MASK		0

# define ESC		53
# define NUM_2		84
# define NUM_4		86
# define NUM_6		88
# define NUM_7		89
# define NUM_8		91
# define NUM_9		92
# define MAIN_KEY_I 34
# define MAIN_KEY_R 15
# define MAIN_KEY_B 11
# define MAIN_KEY_G 5

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

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef	struct		s_rot
{
	double			x;
	double			y;
	double			z;
}					t_rot;

typedef	struct		s_var
{
	int				height;
	int				width;
	int				s_max;
	int				color;
	int				colorMin;
	int				colorMax;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				x;
	int				y;
	int				scale_x;
	int				scale_y;
	t_point			**map_o;
	t_point			**map_r;
	t_img			*img;
}					t_var;

t_var       		*init_var(int fd, char *str);

t_img				*init_img(char *str);

void				key_init(t_var *var);

int					update(t_var *var);

void				s_max(t_var *var);

int					termin(void *param);

int					terminate(char *str);

void				parsing_line(t_var *var, char *line);

char				*parsing_fdf(int fd, t_var **var);

void				set_colors(t_var *var, int minZ, int maxZ);

void				display(t_var *var);

int             	get_color(t_var *var, t_point start, t_point end);

int					key_down(int key, t_var *var);

void				rotate(t_var *var, char axis, t_rot **rot);

void				iso(t_var *var);

#endif
