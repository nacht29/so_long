#include "../../includes/so_long.h"

/*
*uses mlx_hook to read keyboard and mouse input
*
*validates a map and generates a window depending on the 
dimension of the text block in .ber file
*/
void	init_map_win(t_mlx *mlx, char *map, t_map **map_data)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx, "mlx malloc error");

	mlx->win_x = calc_x_size(map);
	mlx->win_y = calc_y_size(map);
	if (mlx->win_x <= 0 || mlx->win_y <= 0)
		err_and_exit(&mlx, "Invalid map dimensions");

	init_map_data(map_data, &mlx);
	(*map_data)->full_map = read_map(map, mlx->win_y);
	int i = 0;
	while ((*map_data)->full_map[i] != NULL)
	{
		printf("%s\n", (*map_data)->full_map[i]);
		i++;
	}
	// mlx_hook(mlx->win_ptr, 2, 1L<<0, key_hook, mlx);
	// mlx_hook(mlx->win_ptr, 17, 0, escape, mlx);
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
