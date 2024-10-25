#include "../../includes/so_long.h"

int	map_check(char *map, int size_y, t_map **elements)
{
	int		fd;
	int		row;
	char	*line;
	char	*trim;

	row = 0;
	fd = open(map, O_RDONLY);
	while (++row <= size_y)
	{
		line = get_next_line(fd);
		trim = ft_strtrim(line, "\n");
		free(line);
		line = trim;
		if (ft_strchr(line, ' ') != NULL || ft_strchr(line, '\t') != NULL)
			return (FALSE);
		if (is_surrounded(row, size_y, line) == FALSE)
			return (FALSE);
		if (check_elements(row, size_y, line, elements) == FALSE)
			return (FALSE);
		free(trim);
	}
	return (valid_count(*elements));
}

int	is_surrounded(int row, int size_y, char *line)
{
	if (row == 1 || row == size_y)
		return (check_top_bottom(line));
	else
		return (check_middle(line));
}

int	check_elements(int row, int size_y, char *line, t_map **elements)
{
	if (row == 1 || row == size_y)
		return (TRUE);
	return (count_elements(elements, line));
}
