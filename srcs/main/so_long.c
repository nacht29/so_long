#include "../../includes/so_long.h"

int	main(int ac, char *av[])
{
	int		fd;
	t_mlx	*mlx;
	t_map	*elements;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd <= 0)
	{
		printf("Usage: ./so_long assets/maps/valid/<map_name>.ber\n");
		exit(EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	init_map(mlx, av[1], &elements);
	mlx_loop(mlx->mlx_ptr);
}

/*
*initiates element struct
*/
void	init_elem_stuct(t_map **elements, t_mlx **mlx)
{
	(*elements) = malloc(sizeof(t_map));
	if (elements == NULL)
		err_and_exit(mlx, "malloc error");
	(*elements)->player_count = 0;
	(*elements)->item_count = 0;
	(*elements)->exit_count = 0;
}

/*
*uses mlx_hook to read keyboard and mouse input
*
*validates a map and generates a window depending on the 
dimension of the text block in .ber file
*/
void	init_map(t_mlx *mlx, char *map, t_map **elements)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		err_and_exit(&mlx, "mlx malloc error");

	mlx->win_x = calc_x_size(map) * 50;
	mlx->win_y = calc_y_size(map) * 50;
	if (mlx->win_x <= 0 || mlx->win_y <= 0)
		err_and_exit(&mlx, "Invalid map dimensions");

	init_elem_stuct(elements, &mlx);
	if (map_check(map, (mlx->win_y / 50), elements) == FALSE)
		err_and_exit(&mlx, "Invalid map design");

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "so_long");
	if (mlx->win_ptr == NULL)
		err_and_exit(&mlx, "mlx malloc error");

	mlx_hook(mlx->win_ptr, 2, 1L<<0, key_hook, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, escape, mlx);
}

/*
*prints custom err msg
*
*frees mlx struct and mlx_ptr
*
*exit code failure
*/
void	err_and_exit(t_mlx **mlx, char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free((*mlx)->mlx_ptr);
	free(*mlx);
	exit(EXIT_FAILURE);
}
