#include "../../includes/so_long.h"


void	init_game(t_mlx *mlx, t_map *map_data, t_sprites *sprites)
{
	int	row;
	int	col;
	
	row = -1;
	while (map_data->full_map[++row])
	{
		col = -1;
		while (map_data->full_map[row][++col])
		{
			if (map_data->full_map[row][col] == '1')
				render(mlx, sprites->wall, col, row);
			else if (map_data->full_map[row][col] == '0')
				render(mlx, sprites->floor, col, row);
			else if (map_data->full_map[row][col] == 'C')
				render(mlx, sprites->item, col, row);
			else if (map_data->full_map[row][col] == 'E')
				render(mlx, sprites->exit_open, col, row);
			else if (map_data->full_map[row][col] == 'P')
				render(mlx, sprites->player, col, row);
		}
	}	
}

void	render(t_mlx *mlx, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr,
							img, wid * 32,
							hgt * 32);
}

