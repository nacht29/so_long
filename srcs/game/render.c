// #include "../../includes/so_long.h"

// void	write_to_window(t_mlx *mlx, t_map *map_data)
// {
// 	int	row;
// 	int	col;

// 	row = -1;
// 	while (map_data->full_map[++row])
// 	{
// 		col = 0;
// 		if (map_data->full_map[row][col] == WALL)
// 			render(mlx, mlx, col, row);
// 		col++;
// 	}
// }

// void	render(t_mlx *mlx, void *img, int wid, int hgt)
// {
// 	mlx_put_image_to_window(mlx->mlx_ptr,
// 							mlx->win_ptr,
// 							img, wid * 32,
// 							hgt * 32);
// }

