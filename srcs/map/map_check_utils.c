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

int	count_elements(t_map **elements, char *line)
{
	while (*line)
	{
		if (*line == 'P')
			(*elements)->player_count++;
		else if (*line == 'C')
			(*elements)->item_count++;
		else if (*line == 'E')
			(*elements)->exit_count++;
		else
			return (FALSE);
		line++;
	}
	return (valid_count(*elements));
}

int	valid_count(t_map *elements)
{
	if (elements->player_count != 1 || elements->exit_count != 1)
		return (FALSE);
	if (elements->item_count < 1)
		return (FALSE);
	return (TRUE);
}
