#include "../../includes/so_long_bonus.h"

static void	player_movement(t_mlx *mlx, int col, int row, int p_state);
static void	render(t_mlx *mlx, void *img, int wid, int hgt);

void	write_img_to_win(t_mlx *mlx, char **full_map, int p_state, int e_state)
{
	int	row;
	int	col;

	row = -1;
	while (full_map[++row])
	{
		col = -1;
		while (full_map[row][++col])
		{
			if (full_map[row][col] == '1')
				render(mlx, mlx->sprites->wall, col, row);
			else if (full_map[row][col] == '0')
				render(mlx, mlx->sprites->floor, col, row);
			else if (full_map[row][col] == 'C')
				render(mlx, mlx->sprites->item, col, row);
			else if (full_map[row][col] == 'E' && e_state == FALSE)
				render(mlx, mlx->sprites->exit_close, col, row);
			else if (full_map[row][col] == 'E' && e_state == TRUE)
				render(mlx, mlx->sprites->exit_open, col, row);
			else if (full_map[row][col] == 'P')
				player_movement(mlx, col, row, p_state);
			else if (full_map[row][col] == 'X')
				render(mlx, mlx->sprites->enemy->down, col, row);
		}
	}	
}

/*
*simplifies process of putting img to the window
*runs mlx_put_image_to_window
*/
static void	render(t_mlx *mlx, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr,
							img,
							hgt * SIZE,
							wid * SIZE);
}

static void	player_movement(t_mlx *mlx, int col, int row, int p_state)
{
	if (p_state == LEFT)
		render(mlx, mlx->sprites->player->left, col, row);
	else if (p_state == RIGHT)
		render(mlx, mlx->sprites->player->right, col, row);
	else if (p_state == UP)
		render(mlx, mlx->sprites->player->up, col, row);
	else if (p_state == DOWN)
		render(mlx, mlx->sprites->player->idle, col, row);
	else if (p_state == IDLE)
		render(mlx, mlx->sprites->player->idle, col, row);
}
