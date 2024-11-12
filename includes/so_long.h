#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>

# ifdef __APPLE__
#  define KEY_ESC 0x35
#  define KEY_W 0x0D
#  define KEY_UP 0x7E
#  define KEY_A 0x00
#  define KEY_LEFT 0x7B
#  define KEY_S 0x01
#  define KEY_DOWN 0x7D
#  define KEY_D 0x02
#  define KEY_RIGHT 0x7C
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_UP 65362
#  define KEY_A 97
#  define KEY_LEFT 65361
#  define KEY_S 115
#  define KEY_DOWN 65364
#  define KEY_D 100
#  define KEY_RIGHT 65363
# endif

# define SIZE 50
# define FALSE 0
# define TRUE 1
# define EXIT_OPEN 2
# define GAME_OVER 3
# define GAME_LOST -4
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define ITEM 'C'
# define LEFT 110
# define RIGHT 120
# define UP 130
# define DOWN 140
# define IDLE 141
# define W_PATH "assets/sprites/Tiles/wall.xpm"
# define F_PATH "assets/sprites/Tiles/floor.xpm"
# define C_PATH "assets/sprites/Items/star_00.xpm"
# define E0_PATH "assets/sprites/Exit/exit_close.xpm"
# define E1_PATH "assets/sprites/Exit/exit_open.xpm"
# define PI_PATH "assets/sprites/Player/player_down.xpm"
# define PU_PATH "assets/sprites/Player/player_up.xpm"
# define PD_PATH "assets/sprites/Player/player_down00.xpm"
# define PL_PATH "assets/sprites/Player/player_left.xpm"
# define PR_PATH "assets/sprites/Player/player_right.xpm"
# define EN_DOWN "assets/sprites/Enemy/enemy_down.xpm"

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_x;
	int					win_y;
	char				**map_dup;
	struct s_map		*map_data;
	struct s_sprites	*sprites;
}	t_mlx;

typedef struct s_map
{
	int				map_x;
	int				map_y;
	int				player_count;
	int				item_count;
	int				collected;
	int				exit_count;
	int				enemy_count;
	int				moves;
	char			**full_map;
}	t_map;

typedef struct s_sprites
{
	void			*wall;
	void			*floor;
	void			*item;
	void			*exit_open;
	void			*exit_close;
	struct s_player	*player;
	struct s_enemy	*enemy;	
}	t_sprites;

typedef struct s_player
{
	void	*idle;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	int		moves;
}	t_player;

typedef struct	s_enemy
{
	void	*down;
}	t_enemy;

/*****************/
/*GETTING STARTED*/
/*****************/

/*init mlx*/

void	init_mlx(int ac, char *av[], t_mlx **mlx);
void	err_and_exit(t_mlx **mlx, char *err_msg);
void	free_mlx(t_mlx **mlx);

/****************/
/*ALL ABOUT MAPS*/
/****************/

/*init map resources*/

void	init_map(t_mlx **mlx, char *map);
void	init_map_data(t_mlx **mlx, char *map, int size_y);
char	**read_map(char *map, int size_y);
void	free_mlx(t_mlx **mlx);

/*checking map*/

int		calc_row(char **map, int size_y);
int		calc_col(char *map);
int		map_check(t_mlx **mlx, int size_y);
int		is_surrounded(int row, int size_y, char *line);
int		check_count_elem(t_mlx **mlx, int row, int size_y, char *line);
int		valid_count(t_map *map_data);

/*******************/
/*WINDOW AND IMAGES*/
/*******************/

/*setting up window*/
void	init_win_key(t_mlx **mlx);
void	flood_fill(t_mlx **mlx);
void	fill(char ***map_dup, int row, int col, t_mlx *mlx, int *exit);

/*loading sprites*/

void	init_sprites(t_mlx **mlx);
void	load_sprites(t_mlx *mlx, t_sprites **sprites);

/*putting img on window*/

void	write_img_to_win(t_mlx *mlx, char **full_map, int p_state, int e_state);

/***********************/
/*KEYBINDS AND CONTROLS*/
/***********************/

int		key_hook(int keycode, t_mlx *mlx);
int		escape(t_mlx *mlx);
void	quit_game(t_mlx *mlx, int act_code);
void	locate_player(t_mlx *mlx, int **player_loc);
int		valid_movement(char **map_dup, int row, int col);
int		remaining_item(char **map_dup);
void	move_up(t_mlx *mlx, int **player_loc, int *move_count);
void	move_down(t_mlx *mlx, int **player_loc, int *move_count);
void	move_left(t_mlx *mlx, int **player_loc, int *move_count);
void	move_right(t_mlx *mlx, int **player_loc, int *move_count);

/**********/
/*GAMEPLAY*/
/**********/

/*main game*/

void	gameplay(t_mlx **mlx);
void	show_steps(t_mlx *mlx, int step_count);

/*enemy movement*/

void	teleport_up(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state, int e_state);
void	teleport_down(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state, int e_state);
void	teleport_left(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state, int e_state);
void	teleport_right(t_mlx **mlx, int *player_loc, int *enemy_loc, int p_state, int e_state);
int		*locate_enemy(t_mlx *mlx);
void	move_enemy(int exec, t_mlx *mlx, int *player_loc, int p_state, int e_state);
#endif
