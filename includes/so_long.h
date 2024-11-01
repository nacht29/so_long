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
# define L 110
# define R 120
# define U 130
# define I_D 140
# define W_PATH "assets/sprites/textures/Tiles/block.xpm"
# define F_PATH "assets/sprites/textures/Tiles/midBlocks_02.xpm"
# define C_PATH "assets/sprites/textures/Items/star_00.xpm"
# define E0_PATH "assets/sprites/textures/Exit/exit_close.xpm"
# define E1_PATH "assets/sprites/textures/Exit/exit_open.xpm"
# define P0_PATH "assets/sprites/textures/Player/walkDown_00.xpm"
# define PL_PATH "assets/sprites/textures/Player/walkLeft_00.xpm"
# define PR_PATH "assets/sprites/textures/Player/walkRight_00.xpm"
# define PU_PATH "assets/sprites/textures/Player/walkUP_00.xpm"

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_x;
	int					win_y;
	struct s_map		*map_data;
	struct s_sprites	*sprites;
	struct s_player		*player;
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
	void	*idle;
	void	*up;
	void	*left;
	void	*right;
	int		moves;
}	t_player;

typedef struct s_sprites
{
	void			*wall;
	void			*floor;
	void			*item;
	void			*exit_open;
	void			*exit_close;
	struct s_player	*player;
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

void	init_win_key(t_mlx **mlx, char *map, t_map **map_data);
int		flood_fill();

/*loading sprites*/

void	init_sprites(t_mlx **mlx, t_map **map_data, t_sprites **sprites);
void	load_sprites(t_mlx **mlx, t_sprites **sprites);
void	load_player_sprites(t_mlx **mlx, t_sprites **sprites);

/*writing images to window*/

void	write_img_to_win(t_mlx *mlx, char **full_map, t_sprites *sprites, int side);
void	player_movement(t_mlx *mlx, t_sprites *sprites, int col, int row, int side);
void	render(t_mlx *mlx, void *img, int wid, int hgt);
// void	write_to_window(t_mlx *mlx, t_map *map_data, t_sprites *sprites);

/**********/
/*CONTROLS*/
/**********/

int		key_hook(int keycode, t_mlx *mlx);
int		escape(t_mlx *mlx);
void	locate_player(t_mlx *mlx, int **player_loc);
int		valid_movement(char **map_dup, int row, int col);
void	move_up(t_mlx *mlx, int **player_loc);
void	move_down(t_mlx *mlx, int **player_loc);
void	move_left(t_mlx *mlx, int **player_loc);
void	move_right(t_mlx *mlx, int **player_loc);

/***********/
/*MAIN GAME*/
/***********/

void	game(t_mlx **mlx, char *map, t_map **map_data);

#endif