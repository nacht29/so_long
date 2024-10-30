#include "../../includes/so_long.h"

/*
*checks if the top and bottom of the map consisst of walls (1) only
*/
int	check_top_bottom(char *line)
{
	while (*line && *line == '1')
		line++;
	if (*line == '\0')
		return (TRUE);
	return (FALSE);
}

/*
*checks if the middle part of the map is surrounded on both ends
*/
int	check_middle(char *line)
{
	size_t	end;

	end = ft_strlen(line) - 1;
	if (line[0] == '1' && line[end] == '1')
		return (TRUE);
	return (FALSE);
}

/*
*record the number of each element
*returns FALSE if invalid char is spotted
*/
int	count_elements(t_map **map_data, char *line)
{
	while (*line)
	{
		if (*line == 'P')
			(*map_data)->player_count++;
		else if (*line == 'C')
			(*map_data)->item_count++;
		else if (*line == 'E')
			(*map_data)->exit_count++;
		else if (*line != '0' && *line != '1')
			return (FALSE);
		line++;
	}
	return (TRUE);
}

/*
*checks if map contains the right amount of each element
-P = 1
-E = 1
-C >= 1
*
*not to be confused with count_elements, as the function mainly records
the number of each element found in the map, and returns FALSE if an 
invalid char is found
*/
int	valid_count(t_map *map_data)
{
	if (map_data->player_count != 1 || map_data->exit_count != 1)
		return (FALSE);
	if (map_data->item_count < 1)
		return (FALSE);
	return (TRUE);
}
