/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:58:56 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 17:58:56 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_mlx	*mlx;

	init_mlx(ac, av, &mlx);
	init_map(&mlx, av[1]);
	gameplay(&mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	init_mlx(int ac, char *av[], t_mlx **mlx)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long assets/maps/valid/<map_name>.ber\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Unable to locate or open file\n");
		exit(EXIT_FAILURE);
	}
	(*mlx) = malloc(sizeof(t_mlx));
	if ((*mlx) == NULL)
		exit(EXIT_FAILURE);
	(*mlx)->map_data = NULL;
	(*mlx)->sprites = NULL;
}

void	err_and_exit(t_mlx **mlx, char *err_msg)
{
	ft_printf("%s\n", err_msg);
	free_mlx(mlx);
	exit(EXIT_FAILURE);
}

void	free_mlx(t_mlx **mlx)
{
	int	i;

	if ((*mlx)->map_data != NULL)
	{
		i = -1;
		if ((*mlx)->map_data->full_map != NULL)
		{
			while ((*mlx)->map_data->full_map[++i])
				free((*mlx)->map_data->full_map[i]);
		}
		free((*mlx)->map_data);
	}
	if ((*mlx)->sprites != NULL)
	{
		if ((*mlx)->sprites->player != NULL)
			free((*mlx)->sprites->player);
		if ((*mlx)->sprites->enemy != NULL)
			free((*mlx)->sprites->enemy);
		free((*mlx)->sprites);
	}
	free(*mlx);
}
