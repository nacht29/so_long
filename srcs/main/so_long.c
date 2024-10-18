#include "../../includes/so_long.h"

/*
if (ac != 2)
	{
		printf("Usage: ./so_long assets/maps/<map_name>.ber");
		exit(EXIT_FAILURE);
	}
*/
int	main(int ac, char *av[])
{
	t_mlx	*mlx;
	int		fd;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);    
	init_map(mlx, av[1]);
	mlx_loop(mlx->mlx_ptr);
}

void	init_map(t_mlx *mlx, char *path)
{
	int	size;

	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx);
	size = calc_map_size(path);
	if (size <= 0)
		err_and_exit(&mlx);
	mlx->win_x = size * 100;
	mlx->win_y = size * 100;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_x, "so_long");
	if (mlx->win_ptr == NULL)
		err_and_exit(&mlx);
	mlx_hook(mlx->win_ptr, 2, 1L<<0, key_hook, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, escape, mlx);
}

void	err_and_exit(t_mlx **mlx)
{
	free(*mlx);
	exit(EXIT_FAILURE);
}

#include <stdio.h>
int	calc_map_size(char *map)
{
	int			fd;
	size_t		fixed_size;
	char		*line;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	ft_printf("line %s", line);
	fixed_size = ft_strlen(line);
	printf("len: %zu\n", fixed_size);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != fixed_size)
			return (-1);
		free(line);
	}
	return ((int)fixed_size);
}
