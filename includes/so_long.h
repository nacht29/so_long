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
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define ITEM 'C'
# define W_PATH "assets/sprites/textures/Tiles/block.xpm"
# define F_PATH "assets/sprites/textures/Tiles/midBlocks_02.xpm"
# define E0_PATH "assets/sprites/textures/Tiles/exit_close.xpm"
# define E1_PATH "assets/sprites/textures/Tiles/exit_open.xpm"

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_x;
	int				win_y;
	struct s_map	*map;
	struct s_player	*player;
}	t_mlx;

typedef struct s_map
{
	int				map_x;
	int				map_y;
	int				player_count;
	int				item_count;
	int				collected;
	int				exit_count;
	int				moves;
	char			**full_map;
	struct s_img	**tiles;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
	int		moves;
}	t_player;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*player;
}	t_sprites;

/*****************/
/*GETTING STARTED*/
/*****************/

/*init mlx*/

void	init_mlx(int ac, char *av[], t_mlx **mlx);
void	err_and_exit(t_mlx **mlx, char *err_msg);

/****************/
/*ALL ABOUT MAPS*/
/****************/

/*init map resources*/

void	init_map(t_mlx **mlx, char *map, t_map **map_data);
void	init_map_data(t_map **map_data, t_mlx **mlx);
char	**read_map(char *map, int size_y);
void	free_mlx_data(t_mlx **mlx);
void	free_map_data(t_map **map_data);

/*checking map*/

int		calc_x_size(char *map);
int		calc_y_size(char *map);
int		map_check(char **full_map, int size_y, t_map **map_data);
int		is_surrounded(int row, int size_y, char *line);
int		check_elements(int row, int size_y, char *line, t_map **map_data);

/*checking utils*/

int		check_top_bottom(char *line);
int		check_middle(char *line);
int		count_elements(t_map **map_data, char *line);
int		valid_count(t_map *map_data);

/*******************/
/*WINDOW AND IMAGES*/
/*******************/

/*setting up window*/

void	init_win(t_mlx **mlx, char *map, t_map **map_data);
int		flood_fill();

/*loading sprites*/

void	init_sprites(t_mlx **mlx, t_map **map_data, t_sprites **sprites);
void	load_sprites(t_mlx **mlx, t_sprites **sprites);

/*writing images to window*/

void	write_to_window(t_mlx *mlx, t_map *map_data, t_sprites *sprites);
void	render(t_mlx *mlx, void *img, int wid, int hgt);

/**********/
/*CONTROLS*/
/**********/

int		key_hook(int keycode, t_mlx *mlx);
int		escape(t_mlx *mlx);


void	game(t_mlx **mlx, t_map **map_data);
#endif