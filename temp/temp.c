// //  main

// /*
// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*mlx_window;
// 	t_tile	tile;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr == NULL)
// 		return (1);
// 	mlx_window = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
// 	if (mlx_window == NULL)
// 	{
// 		mlx_destroy_display(mlx_ptr);
// 		free(mlx_ptr);
// 		return (1);
// 	}
// 	tile.img = mlx_new_image(mlx_ptr, 1920, 1080);
// 	tile.addr = mlx_get_data_addr(tile.img, &tile.bpp, &tile.line_length,
// 								&tile.endian);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
// */


// int	is_surrounded(char *map, int size_y)
// {
// 	int		fd;
// 	int		row;
// 	char	*line;

// 	row = 1;
// 	while (row++ <+ size_y)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (row == 1 || row == size_y)
// 		{
// 			if (all_walls(line) == FALSE)
// 				return (FALSE);
// 		}
// 		else
// 		{
// 			if (both_ends(line) == FALSE)
// 				return (FALSE);
// 		}
// 	}
// 	return (TRUE);
// }

// int	all_walls(char *line)
// {
// 	while (*line && *line == '1')
// 		line++;
// 	if (*line == '\0')
// 		return (TRUE);
// 	else
// 		return (FALSE);
// }

// int	both_ends(char *line)
// {
// 	size_t	end;

// 	end = ft_strlen(line);
// 	if (line[0] == '1' && line[end] == '1')
// 		return (TRUE);
// 	else
// 		return (FALSE);
// }

// int main(int ac, char *av[])
// {
// 	int		fd;
// 	char	*line;

// 	if (ac < 2)
// 		return (1);
// 	fd = open(av[1], O_RDONLY);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		if (ft_strchr(line, ' ') != NULL)
// 			printf("fk\n");
// 		free(line);
// 	}
// }