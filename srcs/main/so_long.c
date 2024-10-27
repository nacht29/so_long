#include "../../includes/so_long.h"

int	main(int ac, char *av[])
{
	int		fd;
	t_mlx	*mlx;
	t_map	*map_data;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd <= 0)
	{
		printf("Usage: ./so_long assets/maps/valid/<map_name>.ber\n");
		exit(EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	init_map_win(mlx, av[1], &map_data);
	mlx_loop(mlx->mlx_ptr);
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
	free((*mlx)->mlx_ptr);
	free(*mlx);
	exit(EXIT_FAILURE);
}
