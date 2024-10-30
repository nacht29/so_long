#include "../../includes/so_long.h"

void	init_sprites(t_mlx **mlx, t_map **map_data, t_sprites **sprites)
{
	*sprites = malloc(sizeof(t_sprites));
	if (*sprites == NULL)
	{
		free_mlx_data(mlx);
		free_map_data(map_data);
		err_and_exit(mlx, "sprites malloc error");
	}
	load_sprites(mlx, sprites);
}

void	load_sprites(t_mlx **mlx, t_sprites **sprites)
{
	int	width;
	int	height;

	(*sprites)->wall = mlx_xpm_file_to_image((*mlx)->mlx_ptr, W_PATH,
											&width, &height);
	(*sprites)->floor = mlx_xpm_file_to_image((*mlx)->mlx_ptr, F_PATH,
											&width, &height);
	(*sprites)->item = mlx_xpm_file_to_image((*mlx)->mlx_ptr, C_PATH,
											&width, &height);
	(*sprites)->exit_open = mlx_xpm_file_to_image((*mlx)->mlx_ptr, E0_PATH,
											&width, &height);
	(*sprites)->player = mlx_xpm_file_to_image((*mlx)->mlx_ptr, P0_PATH,
											&width, &height);
}
