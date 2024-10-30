#include "../../includes/so_long.h"

void	game(t_mlx **mlx, t_map **map_data)
{
	t_sprites	*sprites;

	init_sprites(mlx, map_data, &sprites);
	write_img_to_win(*mlx, *map_data, sprites);
	// code relevant conditions to win/lose game
}
