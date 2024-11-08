#include "../../includes/so_long_bonus.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	int			*player_loc;
	static int	move_count = 0;

	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
		err_and_exit(&mlx, "Failed to load player\n");
	player_loc[0] = 0;
	player_loc[1] = 0;
	if (keycode == KEY_ESC)
		escape(mlx);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(mlx, &player_loc, &move_count);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(mlx, &player_loc, &move_count);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(mlx, &player_loc, &move_count);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(mlx, &player_loc, &move_count);
	return (0);
}

int	escape(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free_mlx(&mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
