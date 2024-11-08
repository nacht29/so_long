#include "../../includes/so_long_bonus.h"

static char	**copy_map(t_mlx *mlx);
static int	find_exit(char **map_dup);
static void	free_map_dup(char ***map_dup);

void	flood_fill(t_mlx **mlx)
{
	int		*player_loc;
	char	**map_dup;

	map_dup = copy_map(*mlx);
	player_loc = malloc(sizeof(int) * 2);
	if (!player_loc)
	{
		free_map_dup(&map_dup);
		err_and_exit(mlx, "Failed to load player\n");
	}
	locate_player(*mlx, &player_loc);
	fill(&map_dup, player_loc[0], player_loc[1], (*mlx)->win_x, (*mlx)->win_y);
	if (remaining_item(map_dup) != 0 || find_exit(map_dup) == FALSE)
	{
		free_map_dup(&map_dup);
		err_and_exit(mlx, "Invalid map design: "
					"Item or exit inaccessible by player\n");
	}
	free_map_dup(&map_dup);
}

void	fill(char ***map_dup, int row, int col, int size_x, int size_y)
{
	if (row < 0 || row >= size_y || col < 0 || col >= size_x)
		return ;
	if ((*map_dup)[row][col] == '1' || (*map_dup)[row][col] == 'F')
		return ;
	if ((*map_dup)[row][col] == 'X')
		return ;
	if ((*map_dup)[row][col] == 'E' && remaining_item(*map_dup) != 0)
		return ;
	(*map_dup)[row][col] = 'F';
	
	fill(map_dup, row + 1, col, size_x, size_y);
	fill(map_dup, row - 1, col, size_x, size_y);
	fill(map_dup, row, col + 1, size_x, size_y);
	fill(map_dup, row, col - 1, size_x, size_y);
}

static int	find_exit(char **map_dup)
{
	int	row;
	int	col;

	row = -1;
	while (map_dup[++row])
	{
		col = -1;
		while (map_dup[row][++col])
		{
		 if (map_dup[row][col] == 'E' || map_dup[row][col] == 'P')
		 	return (FALSE);
		}
	}
	return (TRUE);
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
	return (map_dup);
}

static void	free_map_dup(char ***map_dup)
{
	int	row;

	row = -1;
	while ((*map_dup)[++row])
		free((*map_dup)[row]);
	free(*map_dup);
}
