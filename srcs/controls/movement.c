/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:28 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 17:38:28 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0] - 1, (*player_loc)[1]);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER || act_code == GAME_LOST)
		quit_game(mlx, act_code);
	(*move_count)++;
	if (act_code == EXIT_OPEN)
		move_enemy(*move_count, mlx, *player_loc, UP, TRUE);
	else
		move_enemy(*move_count, mlx, *player_loc, UP, FALSE);
	map_dup[(*player_loc)[0] - 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, UP, TRUE);
	else
		write_img_to_win(mlx, map_dup, UP, FALSE);
}

void	move_down(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0] + 1, (*player_loc)[1]);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER || act_code == GAME_LOST)
		quit_game(mlx, act_code);
	(*move_count)++;
	if (act_code == EXIT_OPEN)
		move_enemy(*move_count, mlx, *player_loc, DOWN, TRUE);
	else
		move_enemy(*move_count, mlx, *player_loc, DOWN, FALSE);
	map_dup[(*player_loc)[0] + 1][(*player_loc)[1]] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, DOWN, TRUE);
	else
		write_img_to_win(mlx, map_dup, DOWN, FALSE);
}

void	move_left(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] - 1);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER || act_code == GAME_LOST)
		quit_game(mlx, act_code);
	(*move_count)++;
	if (act_code == EXIT_OPEN)
		move_enemy(*move_count, mlx, *player_loc, LEFT, TRUE);
	else
		move_enemy(*move_count, mlx, *player_loc, LEFT, FALSE);
	map_dup[(*player_loc)[0]][(*player_loc)[1] - 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, LEFT, TRUE);
	else
		write_img_to_win(mlx, map_dup, LEFT, FALSE);
}

void	move_right(t_mlx *mlx, int **player_loc, int *move_count)
{
	char	**map_dup;
	int		act_code;

	map_dup = mlx->map_data->full_map;
	locate_player(mlx, player_loc);
	act_code = valid_movement(map_dup, (*player_loc)[0], (*player_loc)[1] + 1);
	if (act_code == FALSE)
		return ;
	else if (act_code == GAME_OVER || act_code == GAME_LOST)
		quit_game(mlx, act_code);
	(*move_count)++;
	if (act_code == EXIT_OPEN)
		move_enemy(*move_count, mlx, *player_loc, RIGHT, TRUE);
	else
		move_enemy(*move_count, mlx, *player_loc, RIGHT, FALSE);
	map_dup[(*player_loc)[0]][(*player_loc)[1] + 1] = 'P';
	map_dup[(*player_loc)[0]][(*player_loc)[1]] = '0';
	if (act_code == EXIT_OPEN)
		write_img_to_win(mlx, map_dup, RIGHT, TRUE);
	else
		write_img_to_win(mlx, map_dup, RIGHT, FALSE);
}

void	move(char ***map_dup, int row, int col)
{
	(*map_dup)[row][col] = 'P';
}
