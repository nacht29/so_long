#include "../../includes/so_long.h"

/*
*detects keyboard input and perform certain actions depending
on the keycode received
*
*used in tandem with mlx_hook (so_long,c line 40)
*/
int	key_hook(int keycode, t_mlx *mlx)
{
	int	*player_loc;

	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
		return (1);
	player_loc[0] = 0;
	player_loc[1] = 0;
	if (keycode == ESC)
		escape(mlx);
	if (keycode == UP || keycode == W)
		move_up(mlx, &player_loc);
	else if (keycode == DOWN || keycode == S)
		move_down(mlx, &player_loc);
	else if (keycode == LEFT || keycode == 'A')
		move_left(mlx, &player_loc);
	else if (keycode == RIGHT || keycode == 'D')
		move_right(mlx, &player_loc);
	free(player_loc);
	return (0);
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
