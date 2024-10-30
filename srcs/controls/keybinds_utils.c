#include "../../includes/so_long.h"

/*
*closes window
*
*frees mlx struct and mlx_ptr
*
exits programme with code success
*/
int	escape(t_mlx **mlx)
{
	mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	mlx_destroy_display((*mlx)->mlx_ptr);
	free((*mlx)->mlx_ptr);
	free(*mlx);
	(*mlx)->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/*
code the functions needed to generate diff images 
when diff control key is pressed

especially movement keys
*/
