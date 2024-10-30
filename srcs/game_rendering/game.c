#include "../../includes/so_long.h"

void	game(t_mlx **mlx, t_map **map_data)
{
	t_sprites	*sprites;

	init_sprites(mlx, map_data, &sprites);
	init_game(*mlx, *map_data, sprites);
	// write_to_window(*mlx, *map_data, sprites);
}
