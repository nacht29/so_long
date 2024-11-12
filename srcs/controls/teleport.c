/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:31 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 17:38:31 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	teleport_up(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state)
{
	int		p_row;
	int		p_col;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (p_row < 2 || map_dup[p_row - 2][p_col] != '0')
		return ;
	if (enemy_loc)
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
	map_dup[p_row - 2][p_col] = 'X';
	if ((*mlx)->ex_state == EXIT_OPEN)
		write_img_to_win(*mlx, map_dup, p_state, TRUE);
	else
		write_img_to_win(*mlx, map_dup, p_state, FALSE);
}

void	teleport_down(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state)
{
	int		p_row;
	int		p_col;
	int		border;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	border = (*mlx)->win_x - 3;
	if (p_row > border || map_dup[p_row + 2][p_col] != '0')
		return ;
	if (enemy_loc)
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
	map_dup[p_row + 2][p_col] = 'X';
	if ((*mlx)->ex_state == EXIT_OPEN)
		write_img_to_win(*mlx, map_dup, p_state, TRUE);
	else
		write_img_to_win(*mlx, map_dup, p_state, FALSE);
}

void	teleport_left(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state)
{
	int		p_row;
	int		p_col;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (p_col < 2 || map_dup[p_row][p_col - 2] != '0')
		return ;
	if (enemy_loc)
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
	map_dup[p_row][p_col - 2] = 'X';
	if ((*mlx)->ex_state == EXIT_OPEN)
		write_img_to_win(*mlx, map_dup, p_state, TRUE);
	else
		write_img_to_win(*mlx, map_dup, p_state, FALSE);
}

void	teleport_right(t_mlx **mlx, int *player_loc,
						int *enemy_loc, int p_state)
{
	int		p_row;
	int		p_col;
	char	**map_dup;

	map_dup = (*mlx)->map_data->full_map;
	p_row = player_loc[0];
	p_col = player_loc[1];
	if (map_dup[p_row][p_col + 2] == '\0' || map_dup[p_row][p_col + 2] != '0')
		return ;
	if (enemy_loc)
		map_dup[enemy_loc[0]][enemy_loc[1]] = '0';
	map_dup[p_row][p_col + 2] = 'X';
	if ((*mlx)->ex_state == EXIT_OPEN)
		write_img_to_win(*mlx, map_dup, p_state, TRUE);
	else
		write_img_to_win(*mlx, map_dup, p_state, FALSE);
}
