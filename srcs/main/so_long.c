#include "../../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	*mlx;
	t_map	*map_data;

	init_mlx(ac, av, &mlx);
	init_map(&mlx, av[1], &map_data);
	init_win(&mlx, av[1], &map_data);
	game(&mlx, &map_data);
	mlx_loop(mlx->mlx_ptr);
	free_map_data(&map_data);
}

void	init_mlx(int ac, char *av[], t_mlx **mlx)
{
	int	fd;

	if (ac != 2 || fd <= 0)
	{
		printf("Usage: ./so_long assets/maps/valid/<map_name>.ber\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	(*mlx) = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);
}

/*
*prints custom err msg
*
*frees mlx struct and mlx_ptr
*
*exit code failure
*/
void	err_and_exit(t_mlx **mlx, char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free_mlx_data(mlx);
	exit(EXIT_FAILURE);
}
