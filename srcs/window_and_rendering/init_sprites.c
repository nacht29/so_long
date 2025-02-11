/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:02:31 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 18:02:31 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_player_sprites(t_mlx *mlx, t_sprites **sprites);
static void	load_enemy_sprites(t_mlx *mlx, t_sprites **sprites);

void	init_sprites(t_mlx **mlx)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (sprites == NULL)
		err_and_exit(mlx, "Failed to load game\n");
	load_sprites(*mlx, &sprites);
	(*mlx)->sprites = sprites;
}

void	load_sprites(t_mlx *mlx, t_sprites **sprites)
{
	int	width;
	int	height;

	(*sprites)->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, W_PATH,
			&width, &height);
	(*sprites)->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, F_PATH,
			&width, &height);
	(*sprites)->item = mlx_xpm_file_to_image(mlx->mlx_ptr, C_PATH,
			&width, &height);
	(*sprites)->exit_close = mlx_xpm_file_to_image(mlx->mlx_ptr, E0_PATH,
			&width, &height);
	(*sprites)->exit_open = mlx_xpm_file_to_image(mlx->mlx_ptr, E1_PATH,
			&width, &height);
	load_player_sprites(mlx, sprites);
	load_enemy_sprites(mlx, sprites);
}

static void	load_player_sprites(t_mlx *mlx, t_sprites **sprites)
{
	t_player	*player;
	int			width;
	int			height;

	player = malloc(sizeof(t_player));
	height = 0;
	width = 0;
	if (player == NULL)
		err_and_exit(&mlx, "Failed to load player data\n");
	player->idle = mlx_xpm_file_to_image(mlx->mlx_ptr, PI_PATH,
			&width, &height);
	player->up = mlx_xpm_file_to_image(mlx->mlx_ptr, PU_PATH,
			&width, &height);
	player->down = mlx_xpm_file_to_image(mlx->mlx_ptr, PD_PATH,
			&width, &height);
	player->left = mlx_xpm_file_to_image(mlx->mlx_ptr, PL_PATH,
			&width, &height);
	player->right = mlx_xpm_file_to_image(mlx->mlx_ptr, PR_PATH,
			&width, &height);
	(*sprites)->player = player;
}

static void	load_enemy_sprites(t_mlx *mlx, t_sprites **sprites)
{
	t_enemy		*enemy;
	int			width;
	int			height;

	enemy = malloc(sizeof(t_player));
	if (enemy == NULL)
		err_and_exit(&mlx, "Failed to load enemy data\n");
	enemy->down = mlx_xpm_file_to_image(mlx->mlx_ptr, EN_DOWN,
			&width, &height);
	(*sprites)->enemy = enemy;
}
