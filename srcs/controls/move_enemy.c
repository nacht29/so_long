/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:22 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 17:38:22 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	locate_utils(char **map_dup, int **enemy_loc);

void	move_enemy(int exec, t_mlx *mlx, int *player_loc, int p_state)
{
	int	*enemy_loc;

	enemy_loc = locate_enemy(mlx);
	if (enemy_loc[0] == -1)
		return ;
	if (exec % 3 != 0)
		return ;
	if (p_state == UP)
		teleport_up(&mlx, player_loc, enemy_loc, p_state);
	if (p_state == DOWN)
		teleport_down(&mlx, player_loc, enemy_loc, p_state);
	if (p_state == LEFT)
		teleport_left(&mlx, player_loc, enemy_loc, p_state);
	if (p_state == RIGHT)
		teleport_right(&mlx, player_loc, enemy_loc, p_state);
	free(enemy_loc);
}

int	*locate_enemy(t_mlx *mlx)
{
	int		*enemy_loc;
	char	**map_dup;
	int		flag;

	enemy_loc = malloc(sizeof(int) * 2);
	if (enemy_loc == NULL)
		err_and_exit(&mlx, "Failed to load enemy data\n");
	map_dup = mlx->map_data->full_map;
	flag = locate_utils(map_dup, &enemy_loc);
	if (flag == FALSE)
		enemy_loc[0] = -1;
	return (enemy_loc);
}

static int	locate_utils(char **map_dup, int **enemy_loc)
{
	int		row;
	int		col;
	int		flag;

	row = -1;
	flag = FALSE;
	while (map_dup[++row])
	{
		col = -1;
		while (map_dup[row][++col])
		{
			if (map_dup[row][col] == 'X')
			{
				(*enemy_loc)[0] = row;
				(*enemy_loc)[1] = col;
				flag = TRUE;
				break ;
			}
		}
	}
	return (flag);
}
