#include "../../includes/so_long.h"

/*
*malloc a struct to store all sprites data (img ptrs)
*
*stores sprites data in mlx struct
*/
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
	load_player_sprites(mlx, sprites);
	(*mlx)->sprites = *sprites;
}

/*
*converts xpm file to img ptr to be used readily
*/
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
}

void	load_player_sprites(t_mlx **mlx, t_sprites **sprites)
{
	t_player	*player;
	int			width;
	int			height;

	player= malloc(sizeof(t_player));
	if (player == NULL)
	{
		ft_printf("Unable to load player data\n");
		return ;
	}
	player->idle = mlx_xpm_file_to_image((*mlx)->mlx_ptr, P0_PATH,
											&width, &height);
	player->left = mlx_xpm_file_to_image((*mlx)->mlx_ptr, PL_PATH,
											&width, &height);
	player->right = mlx_xpm_file_to_image((*mlx)->mlx_ptr, PR_PATH,
											&width, &height);
	player->up = mlx_xpm_file_to_image((*mlx)->mlx_ptr, PU_PATH,
											&width, &height);
	(*sprites)->player = player;
}
