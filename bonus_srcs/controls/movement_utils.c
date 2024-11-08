#include "../../includes/so_long_bonus.h"

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
	int	item_count;

	item_count = remaining_item(map_dup);
	if (map_dup[row][col] == '1')
		return (FALSE);
	if (map_dup[row][col] == 'C' && item_count == 1)
		return (SPEC);
	if (map_dup[row][col] == 'E' && item_count != 0)
		return (FALSE);
	else if (map_dup[row][col] == 'E' && item_count == 0)
		return (GAME_OVER);
	if (item_count == 0)
		return (SPEC);
	return (TRUE);
}

int	remaining_item(char **map_dup)
{
	int	row;
	int	col;
	int	item_count;

	row = -1;
	item_count = 0;
	while (map_dup[++row])
	{
		col = -1;
		while (map_dup[row][++col])
		{
		 if (map_dup[row][col] == 'C')
		 	item_count++;
		}
	}
	return (item_count);
}

/*
*prints end of game message depending on outcome
*
*since end_code is act_code, the else condition is added so that
quit_game is triggered only when the act_code signifies end of game
*
*if not, the escape function will be called everytime, ignoring the act_code
*/
void	quit_game(t_mlx *mlx, int end_code)
{
	if (end_code == GAME_OVER)
		ft_printf("Success!\n");
	else if (end_code == GAME_LOST)
		ft_printf("You suck :p\n");
	else
		return ;
	escape(mlx);
}
