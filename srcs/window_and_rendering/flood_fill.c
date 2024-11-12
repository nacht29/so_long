#include "../../includes/so_long.h"

static char	**copy_map(t_mlx *mlx);
static void	free_data(char ***map_dup, int **player_loc);

void	flood_fill(t_mlx **mlx)
{
	int		*player_loc;
	char	**map_dup;
	int		exit;

	map_dup = copy_map(*mlx);
	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
	{
		free_data(&map_dup, &player_loc);
		err_and_exit(mlx, "Failed to load player\n");
	}
	locate_player(*mlx, &player_loc);
	exit = FALSE;
	fill(&map_dup, player_loc[0], player_loc[1], *mlx, &exit);
	if (remaining_item(map_dup) != 0 || exit == FALSE)
	{
		free_data(&map_dup, &player_loc);
		err_and_exit(mlx, "Invalid map design: "
					"Item or exit inaccessible by player\n");
	}
	free_data(&map_dup, &player_loc);
}

void	fill(char ***map_dup, int row, int col, t_mlx *mlx, int *exit)
{
	int	size_x;
	int	size_y;

	size_x = mlx->win_x;
	size_y = mlx->win_y;
	if (row < 0 || row >= size_y || col < 0 || col >= size_x)
		return ;
	if ((*map_dup)[row][col] == '1' || (*map_dup)[row][col] == 'F')
		return ;
	if ((*map_dup)[row][col] == 'X')
		return ;
	if ((*map_dup)[row][col] == 'E' && remaining_item(*map_dup) == 0)
	{
		*exit = TRUE;
		return ;
	}
	else if ((*map_dup)[row][col] == 'E' && remaining_item(*map_dup) != 0)
		return ;
	(*map_dup)[row][col] = 'F';
	fill(map_dup, row + 1, col, mlx, exit);
	fill(map_dup, row - 1, col, mlx, exit);
	fill(map_dup, row, col + 1, mlx, exit);
	fill(map_dup, row, col - 1, mlx, exit);
}

static char	**copy_map(t_mlx *mlx)
{
	char	**map_dup;
	char	**map_sample;
	int		row;

	map_dup = malloc(sizeof(char *) * (mlx->win_y + 1));
	if (map_dup == NULL)
		err_and_exit(&mlx, "Failed to load map\n");
	map_sample = mlx->map_data->full_map;
	row = -1;
	while (map_sample[++row])
		map_dup[row] = ft_strdup(map_sample[row]);
	map_dup[row] = NULL;
	return (map_dup);
}

static void	free_data(char ***map_dup, int **player_loc)
{
	int	row;

	row = -1;
	while ((*map_dup)[++row])
		free((*map_dup)[row]);
	free(*map_dup);
	free(*player_loc);
}
