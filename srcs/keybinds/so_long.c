#include "../../includes/so_long.h"
#include <stdio.h>

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		fprintf(stderr, "Error: mlx_init failed\n");
		return (1);
	}
	mlx_window = mlx_new_window(mlx_ptr, 1000, 1000, "so_long");
	if (mlx_window == NULL)
	{
		fprintf(stderr, "Error: mlx_new_window failed\n");
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	
	printf("Window created successfully. Starting main loop...\n");
	mlx_loop(mlx_ptr);
	return (0);
}
