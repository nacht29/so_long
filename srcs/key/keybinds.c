#include "../../includes/so_long.h"

/*
*detects keyboard input and perform certain actions depending
on the keycode received
*
*used in tandem with mlx_hook (so_long,c line 40)
*/
int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		escape(mlx);
	// add movement keys
}

/*
*closes window
*
*frees mlx struct and mlx_ptr
*
exits programme with code success
*/
int	escape(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
