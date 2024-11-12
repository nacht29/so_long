#include "../../includes/so_long.h"

/*
*checks map line by line:
*-if map contains empty spaces
*-if map is surrounded by wall
*-if map contains valid characters only
*-count and record number of elements
*/
int	map_check(t_mlx **mlx, int size_y)
{
	char	**full_map;
	int		row;

	full_map = (*mlx)->map_data->full_map;
	row = -1;
	while (++row < size_y)
	{
		if (ft_strchr(full_map[row], ' ') != NULL
			|| ft_strchr(full_map[row], '\t') != NULL)
			return (FALSE);
		if (is_surrounded(row + 1, size_y, full_map[row]) == FALSE)
			return (FALSE);
		if (check_count_elem(mlx, row + 1, size_y, full_map[row]) == FALSE)
			return (FALSE);
	}
	return (valid_count((*mlx)->map_data));
}

int	is_surrounded(int row, int size_y, char *line)
{
	size_t	end;

	if (row == 1 || row == size_y)
	{
		while (*line && *line == '1')
			line++;
		if (*line == '\0')
			return (TRUE);
		return (FALSE);
	}
	else
	{
		end = ft_strlen(line) - 1;
		if (line[0] == '1' && line[end] == '1')
			return (TRUE);
		return (FALSE);
	}
}

/*
*identify individual element present in the map and record their count
*
returns FALSE if an invalid element is found
*/
int	check_count_elem(t_mlx **mlx, int row, int size_y, char *line)
{
	if (row != 1 && row != size_y)
	{
		while (*line)
		{
			if (*line == 'P')
				(*mlx)->map_data->player_count++;
			else if (*line == 'C')
				(*mlx)->map_data->item_count++;
			else if (*line == 'E')
				(*mlx)->map_data->exit_count++;
			else if (*line == 'X')
				(*mlx)->map_data->enemy_count++;
			else if (*line != '0' && *line != '1')
			{
				printf("count elem\n");
				return (FALSE);
			}
			line++;
		}
	}
	return (TRUE);
}

/*
*checks if map contains the right amount of each element
-P = 1
-E = 1
-C >= 1
-X = 1
*
*not to be confused with count_elements, as the function mainly records
the number of each element found in the map, and returns FALSE if an 
invalid char is found
*/
int	valid_count(t_map *map_data)
{
	if (map_data->player_count != 1 || map_data->exit_count != 1)
		return (FALSE);
	if (map_data->enemy_count > 1 )
		return (FALSE);
	if (map_data->item_count < 1)
		return (FALSE);
	return (TRUE);
}
