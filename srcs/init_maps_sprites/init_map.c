#include "../../includes/so_long.h"

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
void	init_map(t_mlx **mlx, char *map, t_map **map_data)
{
	(*mlx)->mlx_ptr = mlx_init();
	if ((*mlx)->mlx_ptr == NULL)
		err_and_exit(mlx, "mlx malloc error");
	(*mlx)->win_x = calc_x_size(map);
	(*mlx)->win_y = calc_y_size(map);
	if ((*mlx)->win_x <= 0 || (*mlx)->win_y <= 0)
		err_and_exit(mlx, "Invalid map dimensions");
	init_map_data(map_data, mlx);
	(*map_data)->full_map = read_map(map, (*mlx)->win_y);
	if (map_check((*map_data)->full_map, (*mlx)->win_y, map_data) == FALSE)
	{
		free_map_data(map_data);
		err_and_exit(mlx, "Invalid map design");
	}
}

/*
*initiates struct to store map_data
*will be used in map_check and flood_fill
*/
void	init_map_data(t_map **map_data, t_mlx **mlx)
{
	(*map_data) = malloc(sizeof(t_map));
	if (map_data == NULL)
		err_and_exit(mlx, "malloc error");
	(*map_data)->full_map = NULL;
	(*map_data)->player_count = 0;
	(*map_data)->item_count = 0;
	(*map_data)->exit_count = 0;
}

/*
*read from .ber file and store map design in 2D array
*
*will be used for map_check and flood_fill
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
		full_map[row] = ft_strtrim(line, "\n");
		free(line);
	}
	full_map[size_y] = NULL;
	return (full_map);
}
