#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>

# define ESC 27

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		win_x;
	int		win_y;
}	t_mlx;

typedef struct s_map
{
	int		map_x;
	int		map_y;
	int		item_count;
	int		exit_count;
}	t_map;

typedef struct s_tile
{
	int		tile_x;
	int		tile_y;
	void	*img;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_length;
	int		endian;
}	t_tile;

void	err_and_exit(t_mlx **mlx);

#endif
