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
