#include "../../includes/so_long.h"

/*
*runs flood fill algorithnm to validate map
*
*generates a window if map is correct
*/
void	init_win(t_mlx **mlx, char *map, t_map **map_data)
{
	// flood_fill
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr,
									(*mlx)->win_x * 32,
									(*mlx)->win_y * 32, "so_long");
	if ((*mlx)->win_ptr == NULL)
	{
		free_map_data(map_data);
		err_and_exit(mlx, "mlx window malloc error");
	}
	mlx_hook((*mlx)->win_ptr, 2, 1L<<0, key_hook, mlx);
	mlx_hook((*mlx)->win_ptr, 17, 0, escape, mlx);
}

int	flood_fill()
{
	return (0);
}