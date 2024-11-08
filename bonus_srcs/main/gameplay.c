#include "../../includes/so_long_bonus.h"

/*
*initiates windows and keybinds
*
*loads sprites
*
*renders game at starting point
*/
void	gameplay(t_mlx **mlx)
{
	init_win_key(mlx);
	init_sprites(mlx);
	write_img_to_win(*mlx, (*mlx)->map_data->full_map, IDLE, FALSE);
}

/*
*runs flood fill algorithnm to validate map
*
*generates a window if map is correct
*
*defines keybinds and controls in key_hook function
*
*copies map_data into mlx struct
*/
void	init_win_key(t_mlx **mlx)
{
	flood_fill(mlx);
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr,
									(*mlx)->win_x * 32,
									(*mlx)->win_y * 32, "so_long");
	if ((*mlx)->win_ptr == NULL)
		err_and_exit(mlx, "Failed to load window\n");
	mlx_hook((*mlx)->win_ptr, 2, 1L<<0, key_hook, *mlx);
	mlx_hook((*mlx)->win_ptr, 17, 0, escape, *mlx);
}
