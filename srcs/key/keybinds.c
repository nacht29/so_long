#include "../../includes/so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		escape(mlx);
	// add movement keys
}

int	escape(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
