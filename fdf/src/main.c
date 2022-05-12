#include "fdf.h"

int				main(int ac, char **av)
{
	int			fd;
	t_var		*var;

	if (ac < 2 || !(ft_strstr(av[1], ".fdf")))
		terminate("usage: ./fdf ./test_maps/[file_name].fdf");
	if ((fd = open(av[1], O_RDONLY)) < 3)
		terminate("File could not be found");
	var = init_var(fd, av[1]);
	update(var);
	key_init(var);
	return (0);
}
