//  main

/*
int main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_tile	tile;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_window = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	if (mlx_window == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	tile.img = mlx_new_image(mlx_ptr, 1920, 1080);
	tile.addr = mlx_get_data_addr(tile.img, &tile.bpp, &tile.line_length,
								&tile.endian);
	mlx_loop(mlx_ptr);
	return (0);
}
*/
