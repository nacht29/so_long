#include "../../includes/so_long.h"
#include <stdio.h>

// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*mlx_window;
// 	t_tile	tile;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr == NULL)
// 		return (1);
// 	mlx_window = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
// 	if (mlx_window == NULL)
// 	{
// 		mlx_destroy_display(mlx_ptr);
// 		free(mlx_ptr);
// 		return (1);
// 	}
// 	tile.img = mlx_new_image(mlx_ptr, 1920, 1080);
// 	tile.addr = mlx_get_data_addr(tile.img, &tile.bpp, &tile.line_length,
// 								&tile.endian);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }

int	main(int ac, char *av[])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (ac != 3)
		exit(EXIT_FAILURE);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx);
	mlx->win_x = ft_atoi(av[1]);
	mlx->win_y = ft_atoi(av[2]);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_x, "so_long");
	if (mlx->win_ptr == NULL)
		err_and_exit(&mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	err_and_exit(t_mlx **mlx)
{
	free(*mlx);
	exit(EXIT_FAILURE);
}
