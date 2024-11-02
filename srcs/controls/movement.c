#include "../../includes/so_long.h"

static void	change_exit(char ***map_dup);

void	move_up(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0] - 1, (*player_loc)[1]);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER)
		escape(mlx);
	map_dup[(*player_loc)[0] - 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == SPEC)
		write_img_to_win(mlx, map_dup, UP, TRUE);
	else
		write_img_to_win(mlx, map_dup, UP, FALSE);
}

void	move_down(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0] + 1, (*player_loc)[1]);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER)
		escape(mlx);
	map_dup[(*player_loc)[0] + 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == SPEC)
		write_img_to_win(mlx, map_dup, DOWN, TRUE);
	else
		write_img_to_win(mlx, map_dup, DOWN, FALSE);
}

void	move_left(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] - 1);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER)
		escape(mlx);
	map_dup[(*player_loc)[0]][(*player_loc)[1] - 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == SPEC)
		write_img_to_win(mlx, map_dup, LEFT, TRUE);
	else
		write_img_to_win(mlx, map_dup, LEFT, FALSE);
}

void	move_right(t_mlx *mlx, int **player_loc)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] + 1);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER)
		escape(mlx);
	map_dup[(*player_loc)[0]][(*player_loc)[1] + 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == SPEC)
		write_img_to_win(mlx, map_dup, RIGHT, TRUE);
	else
		write_img_to_win(mlx, map_dup, RIGHT, FALSE);
}
