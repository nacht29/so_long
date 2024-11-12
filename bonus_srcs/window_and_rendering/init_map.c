#include "../../includes/so_long_bonus.h"

/*
*malloc mlx_ptr
*
*checks for map dimension :
*-if dimension is rectangular and map is surrounded
*
*checks for map content:
*-if map contains valid num of valid char
*
*uses mlx_hook to read keyboard and mouse input
*/
void	init_map(t_mlx **mlx, char *map)
{
	(*mlx)->mlx_ptr = mlx_init();
	if ((*mlx)->mlx_ptr == NULL)
		err_and_exit(mlx, "Failed to load map\n");
	(*mlx)->win_y = calc_col(map);
	init_map_data(mlx, map, (*mlx)->win_y);
	if (map_check(mlx, (*mlx)->win_y) == FALSE)
		err_and_exit(mlx, "Invalid map design");
}

/*
*initiates struct to store map_data
*
*map data consists of:
-full map in 2D array
-number of each element
*
*will be used in map_check
*/
void	init_map_data(t_mlx **mlx, char *map, int size_y)
{
	t_map	*map_data;
	map_data = malloc(sizeof(t_map));
	if (map_data == NULL)
		err_and_exit(mlx, "Failed to load map");
	map_data->full_map = read_map(map, size_y);
	(*mlx)->win_x = calc_row(map_data->full_map, (*mlx)->win_y);
	if ((*mlx)->win_x <= 0)
		err_and_exit(mlx, "Failed to load map - x");
	map_data->player_count = 0;
	map_data->item_count = 0;
	map_data->exit_count = 0;
	map_data->enemy_count = 0;
	(*mlx)->map_data = map_data;
}

/*
*read from .ber file and store map design in 2D array
*
*will be used for map_check
*/
char	**read_map(char *map, int size_y)
{
	int		fd;
	int		row;
	char	*line;
	char	**full_map;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	full_map = malloc(sizeof(char *) * (size_y + 1));
	row = -1;
	while (++row < size_y)
	{
		line = get_next_line(fd);
		full_map[row] = ft_strtrim(line, "\n\t\r");
		free(line);
	}
	full_map[size_y] = NULL;
	return (full_map);
}
