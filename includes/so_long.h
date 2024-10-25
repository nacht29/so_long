#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

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

# define TRUE 1
# define FALSE 0

typedef struct s_mlx_data
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
	int		player_count;
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

void	err_and_exit(t_mlx **mlx, char *err_msg);
void	init_map(t_mlx *mlx, char *map, t_map **elements);
void	init_elem_stuct(t_map **elements, t_mlx **mlx);

/*MAP CHECK*/

int		calc_x_size(char *map);
int		calc_y_size(char *map);
size_t	get_x(int fd);
int		map_check(char *map, int size_y, t_map **elements);
int		is_surrounded(int row, int size_y, char *line);
int		check_elements(int row, int size_y, char *line, t_map **elements);
int		check_top_bottom(char *line);
int		check_middle(char *line);
int		count_elements(t_map **elements, char *line);
int		valid_count(t_map *elements);

/*KEYBINDS*/

int		key_hook(int keycode, t_mlx *mlx);
int		escape(t_mlx *mlx);
#endif