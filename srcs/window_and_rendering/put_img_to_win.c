#include "../../includes/so_long.h"

static void	player_movement(t_mlx *mlx, int col, int row, int side);
static void	render(t_mlx *mlx, void *img, int wid, int hgt);

void	write_img_to_win(t_mlx *mlx, char **full_map, int side)
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
			else if (full_map[row][col] == 'E')
				render(mlx, mlx->sprites->exit_open, col, row);
			else if (full_map[row][col] == 'P')
				player_movement(mlx, col, row, side);
		}
	}	
}

static void	player_movement(t_mlx *mlx, int col, int row, int side)
{
	if (side == LEFT)
		render(mlx, mlx->sprites->player->left, col, row);
	else if (side == RIGHT)
		render(mlx, mlx->sprites->player->right, col, row);
	else if (side == UP)
		render(mlx, mlx->sprites->player->up, col, row);
	else if (side == DOWN)
		render(mlx, mlx->sprites->player->idle, col, row);
	else if (side == IDLE)
		render(mlx, mlx->sprites->player->idle, col, row);
}

/*
*simplifies process of putting img to the window
*runs mlx_put_image_to_window
*/
static void	render(t_mlx *mlx, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr,
							img, wid * 32,
							hgt * 32);
}
