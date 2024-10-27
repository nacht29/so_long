#include "../../includes/so_long.h"

int	check_top_bottom(char *line)
{
	while (*line && *line == '1')
		line++;
	if (*line == '\0')
		return (TRUE);
	return (FALSE);
}

int	check_middle(char *line)
{
	size_t	end;

	end = ft_strlen(line) - 1;
	if (line[0] == '1' && line[end] == '1')
		return (TRUE);
	return (FALSE);
}

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

int	valid_count(t_map *map_data)
{
	if (map_data->player_count != 1 || map_data->exit_count != 1)
		return (FALSE);
	if (map_data->item_count < 1)
		return (FALSE);
	return (TRUE);
}
