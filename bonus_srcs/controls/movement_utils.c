#include "../../includes/so_long_bonus.h"
/*
*finds the position of P in the map and return the data in an
int array [row, col]
*/
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
/*
*on key press, checks in step ahead of where the player is trying to move
*
*retruns an 'action code' to decide if:
-player is allowed to move (wall, into enemy, exit)
-game over conditions (into exit when items are collected or into enemy)
*
*action code is received by move_* func to execute specific commands
*/
int	valid_movement(char **map_dup, int row, int col)
{
	int	item_count;

	item_count = remaining_item(map_dup);
	if (map_dup[row][col] == 'X')
		return (GAME_LOST);
	if (map_dup[row][col] == '1')
		return (FALSE);
	if (map_dup[row][col] == 'C' && item_count == 1)
		return (EXIT_OPEN);
	if (map_dup[row][col] == 'E' && item_count != 0)
		return (FALSE);
	else if (map_dup[row][col] == 'E' && item_count == 0)
		return (GAME_OVER);
	if (item_count == 0)
		return (EXIT_OPEN);
	return (TRUE);
}

/*
*counts how many C are present in the map
*used in both movement and flood_fill
*/
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
*exits game with a message when act_code signifies end of game
*/
void	quit_game(t_mlx *mlx, int act_code)
{
	if (act_code == GAME_OVER)
		ft_printf("Success!\n");
	else if (act_code == GAME_LOST)
		ft_printf("You suck :p\n");
	else
		return ;
	escape(mlx);
}
