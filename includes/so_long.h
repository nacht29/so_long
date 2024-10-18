#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>

# ifdef __APPLE__
#  define ESC 0x35
#  define W 0x0D
#  define UP 0x7E
#  define A 0x00
#  define LEFT 0x7B
#  define S 0x01
#  define DOWN 0x7D
#  define D 0x02
#  define RIGHT 0x7C
# else
#  define ESC 65307
#  define W 119
#  define UP 65362
#  define A 97
#  define LEFT 65361
#  define S 115
#  define DOWN 65364
#  define D 100
#  define RIGHT 65363
# endif

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
void	init_map(t_mlx *mlx, char *path);
int		key_hook(int keycode, t_mlx *mlx);
int		escape(t_mlx *mlx);
int		calc_map_size(char *map);
#endif
