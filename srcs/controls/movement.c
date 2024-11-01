#include "../../includes/so_long.h"

void	move_left(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	if (valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] - 1) == FALSE)
		return ;
	map_dup[(*player_loc)[0]][(*player_loc)[1] - 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	write_img_to_win(mlx, map_dup, mlx->sprites, L);
}

void	move_right(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	if (valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] + 1) == FALSE)
		return ;
	map_dup[(*player_loc)[0]][(*player_loc)[1] + 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	write_img_to_win(mlx, map_dup, mlx->sprites, R);
}

void	move_up(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	if (valid_movement(map_dup, (*player_loc)[0] - 1, (*player_loc)[1]) == FALSE)
		return ;
	map_dup[(*player_loc)[0] - 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	write_img_to_win(mlx, map_dup, mlx->sprites, U);
}

void	move_down(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	if (valid_movement(map_dup, (*player_loc)[0] + 1, (*player_loc)[1]) == FALSE)
		return ;
	map_dup[(*player_loc)[0] + 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	write_img_to_win(mlx, map_dup, mlx->sprites, I_D);
}