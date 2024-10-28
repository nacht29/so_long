// #include "../../includes/so_long.h"

// void	init_sprites(t_mlx **mlx, t_map **map_data, t_sprites **sprites)
// {
// 	*sprites = malloc(sizeof(t_sprites));
// 	if (*sprites == NULL)
// 	{
// 		free_mlx_data(mlx);
// 		free_map_data(map_data);
// 		err_and_exit(mlx, "sprites malloc error");
// 	}
	
// }

// void	load_sprites(t_mlx **mlx, t_sprites **sprites)
// {
// 	int	width;
// 	int	height;

// 	(*sprites)->wall = mlx_xpm_file_to_image((*mlx)->mlx_ptr, W_PATH,
// 											&width, &height);
// 	(*sprites)->floor = mlx_xpm_file_to_image((*mlx)->mlx_ptr, F_PATH,
// 											&width, &height);
// }
