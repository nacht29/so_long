#include "../../includes/so_long.h"

int	map_check(char **full_map, int size_y, t_map **map_data)
{
	int	row;

	row = -1;
	while (++row < size_y)
	{
		if (ft_strchr(full_map[row], ' ') != NULL
			|| ft_strchr(full_map[row], '\t') != NULL)
			return (FALSE);
		if (is_surrounded(row + 1, size_y, full_map[row]) == FALSE)
			return (FALSE);
		if (check_elements(row + 1, size_y, full_map[row], map_data) == FALSE)
			return (FALSE);
	}
}

int	is_surrounded(int row, int size_y, char *line)
{
	if (row == 1 || row == size_y)
		return (check_top_bottom(line));
	else
		return (check_middle(line));
}

int	check_elements(int row, int size_y, char *line, t_map **map_data)
{
	if (row == 1 || row == size_y)
		return (TRUE);
	return (count_elements(map_data, line));
}
