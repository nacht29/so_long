#include "../includes/so_long.h"

int	calc_x_size(char *map)
{
	int			fd;
	size_t		fixed_size;
	char		*line;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	fixed_size = ft_strlen(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != fixed_size)
			return (-1);
		free(line);
	}
	return ((int)fixed_size);
}

int	calc_y_size(char *map)
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
