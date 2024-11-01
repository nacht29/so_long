#include "../../includes/so_long.h"

void	locate_player(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;
	int		row;
	int		col;

	map_dup = mlx->map_data->full_map;
	row = -1;
	while (map_dup[++row])
	{
		col = -1;
		while (map_dup[row][++col])
		{
			if (map_dup[row][col] == 'P')
			{
				(*player_loc)[0] = row;
				(*player_loc)[1] = col;
				return ;
			}
		}
	}
}

int	valid_movement(char **map_dup, int row, int col)
{
	if (map_dup[row][col] == '1')
		return (FALSE);
	if (map_dup[row][col] == 'E') // will need modifications later
		return (FALSE);
	return (TRUE);
}
