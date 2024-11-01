#include "../../includes/so_long.h"

/*
*generate map at the start of the game
*/
void	write_img_to_win(t_mlx *mlx, char **full_map, t_sprites *sprites)
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
				render(mlx, sprites->wall, col, row);
			else if (full_map[row][col] == '0')
				render(mlx, sprites->floor, col, row);
			else if (full_map[row][col] == 'C')
				render(mlx, sprites->item, col, row);
			else if (full_map[row][col] == 'E')
				render(mlx, sprites->exit_open, col, row);
			else if (full_map[row][col] == 'P')
				render(mlx, sprites->player, col, row);
		}
	}	
}

/*
*simplifies process of putting img to the window
*runs mlx_put_image_to_window
*/
void	render(t_mlx *mlx, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr,
							img, wid * 32,
							hgt * 32);
}

