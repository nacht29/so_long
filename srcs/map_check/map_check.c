#include "../../includes/so_long.h"

/*
*checks map line by line:
*-if map contains empty spaces
*-if map is surrounded by wall
*-if map contains valid characters only
*-count and record number of elements
*/
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
	return (valid_count(*map_data));
}

int	is_surrounded(int row, int size_y, char *line)
{
	if (row == 1 || row == size_y)
		return (check_top_bottom(line));
	else
		return (check_middle(line));
}

/*
*count elements will return FALSE if any invalid characters is found
*
*it is not to be confused with valid_count, as valid_count is the final check
which verifies if a map contains the right amount of each element
*
*count_elemnts only checks for invalid characters and records the number of
elements contained in the map
*/
int	check_elements(int row, int size_y, char *line, t_map **map_data)
{
	if (row == 1 || row == size_y)
		return (TRUE);
	return (count_elements(map_data, line));
}
