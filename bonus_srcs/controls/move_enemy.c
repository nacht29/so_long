#include "../../includes/so_long_bonus.h"

void	move_enemy(int exec, t_mlx *mlx, int *player_loc, int p_state, int e_state)
{
	if (exec % 3 != 0)
		return ;
	if (p_state == UP)
		teleport_up(&mlx, player_loc, p_state, e_state);
	if (p_state == DOWN)
		teleport_down(&mlx, player_loc, p_state, e_state);
	if (p_state == LEFT)
		teleport_left(&mlx, player_loc, p_state, e_state);
	if (p_state == RIGHT)
		teleport_right(&mlx, player_loc, p_state, e_state);
}

int	*locate_enemy(t_mlx *mlx)
{
	int		*enemy_loc;
	int		row;
	int		col;
	char	**map_dup;

	enemy_loc = malloc(sizeof(int) * 2);
	if (enemy_loc == NULL)
		err_and_exit(&mlx, "Failed to load enemy data\n");
	map_dup = mlx->map_data->full_map;
	row = -1;
	while (map_dup[++row])
	{
		col = -1;
		while (map_dup[row][++col])
		{
			if (map_dup[row][col] == 'X')
			{
				enemy_loc[0] = row;
				enemy_loc[1] = col;
				break;
			}
		}
	}
	return (enemy_loc);
}
