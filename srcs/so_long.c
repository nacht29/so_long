#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	*mlx;
	int		fd;

	if (ac != 2)
	{
		printf("Usage: ./so_long assets/maps/<map_name>.ber");
		exit(EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);    
	init_map(mlx, av[1]);
	mlx_loop(mlx->mlx_ptr);
}

void	init_map(t_mlx *mlx, char *path)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx, "mlx malloc error");
	mlx->win_x = calc_x_size(path) * 50;
	mlx->win_y = calc_y_size(path) * 50;
	if (mlx->win_x <= 0 || mlx->win_y <= 0)
		err_and_exit(&mlx, "Invalid map dimensions");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_x, "so_long");
	if (mlx->win_ptr == NULL)
		err_and_exit(&mlx, "mlx malloc error");
	mlx_hook(mlx->win_ptr, 2, 1L<<0, key_hook, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, escape, mlx);
}

void	err_and_exit(t_mlx **mlx, char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free(*mlx);
	exit(EXIT_FAILURE);
}
