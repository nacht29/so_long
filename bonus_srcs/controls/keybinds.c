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
	{
		free(player_loc);
		escape(mlx);
	}
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(mlx, &player_loc, &move_count);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(mlx, &player_loc, &move_count);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(mlx, &player_loc, &move_count);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(mlx, &player_loc, &move_count);
	show_steps(mlx, move_count);
	ft_printf("Steps taken: %i\n", move_count);
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

void	show_steps(t_mlx *mlx, int step_count)
{
	char	*step;

	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		12, 16, 0x00FFFFFF, "Steps: ");
	step = ft_itoa(step_count);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
		50, 16, 0x00FFFFFF, step);
	free(step);
}
