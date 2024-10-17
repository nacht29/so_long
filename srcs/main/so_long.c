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

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		err_and_exit(&mlx);
	init_map(mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	init_map(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx);
	mlx->win_x = 100;
	mlx->win_y = 100;
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
