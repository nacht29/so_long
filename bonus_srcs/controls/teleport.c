#include "../../includes/so_long_bonus.h"

void	teleport_up(t_mlx **mlx, int *player_loc, int p_state, int e_state)
{
	int		p_row;
	int		p_col;
	int		*enemy_loc;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (p_row < 2 || map_dup[p_row - 2][p_col] != '0')
		return ;
	enemy_loc = locate_enemy(*mlx);
	if (enemy_loc)
	{
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
		free(enemy_loc);
	}	
	map_dup[p_row - 2][p_col] = 'X';
	write_img_to_win(*mlx, map_dup, p_state, e_state);
}

void	teleport_down(t_mlx **mlx, int *player_loc, int p_state, int e_state)
{
	int		p_row;
	int		p_col;
	int		border;
	int		*enemy_loc;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	border = (*mlx)->win_x - 3;
	if (p_row > border || map_dup[p_row + 2][p_col] != '0')
		return ;
	enemy_loc = locate_enemy(*mlx);
	if (enemy_loc)
	{
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
		free(enemy_loc);
	}	
	map_dup[p_row + 2][p_col] = 'X';
	write_img_to_win(*mlx, map_dup, p_state, e_state);
}

void	teleport_left(t_mlx **mlx, int *player_loc, int p_state, int e_state)
{
	int		p_row;
	int		p_col;
	int		*enemy_loc;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (p_col < 2 || map_dup[p_row][p_col - 2] != '0')
		return ;
	enemy_loc = locate_enemy(*mlx);
	if (enemy_loc)
	{
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
		free(enemy_loc);
	}	
	map_dup[p_row][p_col - 2] = 'X';
	write_img_to_win(*mlx, map_dup, p_state, e_state);
}

void	teleport_right(t_mlx **mlx, int *player_loc, int p_state, int e_state)
{
	int		p_row;
	int		p_col;
	int		*enemy_loc;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (map_dup[p_row][p_col + 2] == '\0' || map_dup[p_row][p_col + 2] != '0')
		return ;
	enemy_loc = locate_enemy(*mlx);
	if (enemy_loc)
	{
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
		free(enemy_loc);
	}
	map_dup[p_row][p_col + 2] = 'X';
	write_img_to_win(*mlx, map_dup, p_state, e_state);
}
