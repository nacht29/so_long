#include "../../includes/so_long.h"

int	map_check_lines(char *map, int size_y)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	row = 0;
	while (++row <= size_y)
	{
		line = get_next_line(fd);
		if (row == 1 || row == size_y)
		{
			if (top_bottom(line) == FALSE)
				return (FALSE);
		}
		else
		{
			if (middle(line) == FALSE)
				return (FALSE);
		}
		free(line);
	}
	return (TRUE);
}

int	top_bottom(char *line)
{
	while (*line && *line == '1')
		line++;
	if (*line == '\0')
		return (TRUE);
	return (FALSE);
}

int	middle(char *line)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(line) - 1;
	while (line[i])
	{
		if (i == 0 || i == end)
		{
			if (line[i] != '1')
				return (FALSE);
		}
		else
		{
			if (is_valid_char(line[i]) == FALSE)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	is_valid_char(char c)
{
	char	*valid_chars;

	valid_chars = "01PCE";
	while (*valid_chars)
	{
		if (c == *valid_chars)
			return (TRUE);
		valid_chars++;
	}
	return (FALSE);
}
