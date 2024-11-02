#include "../../includes/so_long.h"

void	gameplay(t_mlx **mlx)
{
	init_win_key(mlx);
	init_sprites(mlx);
	write_img_to_win(*mlx, (*mlx)->map_data->full_map, IDLE, FALSE);
}
