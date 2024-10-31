#include "../../includes/so_long.h"

void	game(t_mlx **mlx, char *map, t_map **map_data)
{
	t_sprites	*sprites;

	init_win_key(mlx, map, map_data);
	init_sprites(mlx, map_data, &sprites);
	write_img_to_win(*mlx, *map_data, sprites);
	// code relevant conditions to win/lose game
}
