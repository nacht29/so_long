/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:01:35 by yachan            #+#    #+#             */
/*   Updated: 2024/11/12 18:01:35 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t	get_x(int fd);

/*
*calculates the horizontal dimension of the map
*checks if each line in the .ber file has the same length 
*/
int	calc_row(char **map, int size_y)
{
	size_t	row;
	size_t	fix_len;

	row = 0;
	fix_len = ft_strlen(map[0]);
	while (++row < size_y)
	{
		if (ft_strlen(map[row]) != fix_len)
			return (-1);
	}
	return (fix_len);
}

/*
*calculates the vertical dimension of the map
*does not perform any checking whatsoever
*/
int	calc_col(char *map)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map, O_RDONLY);
	line_count = 0;
	if (fd < 0)
		return (fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		line_count++;
	}
	return (line_count);
}

static size_t	get_x(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (ft_strchr(line, '\n') != NULL)
		len = ft_strlen(line) - 1;
	else
		len = ft_strlen(line);
	free(line);
	return (len);
}
