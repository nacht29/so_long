#include "../../includes/so_long.h"

void	free_mlx_data(t_mlx **mlx)
{
	free((*mlx)->mlx_ptr);
	free(*mlx);
}

/*
*frees 2D array in map_data
*frees map_data struct
*/
void	free_map_data(t_map **map_data)
{
	int	i;

	i = 0;
	while ((*map_data)->full_map[i])
	{
		free((*map_data)->full_map[i]);
		i++;
	}
	free((*map_data)->full_map);
	free(*map_data);
}
