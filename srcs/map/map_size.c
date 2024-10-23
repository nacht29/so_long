#include "../../includes/so_long.h"

/*
*calculates the horizontal dimension of the map
*checks if each line in the .ber file has the same length 
*/
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
/*
*calculates the vertical dimension of the map
*does not perform any checking whatsoever
*/
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
