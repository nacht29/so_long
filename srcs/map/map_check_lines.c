#include "../../includes/so_long.h"

static int	top_bottom(int row, int size_y, char *line);
static int	middle(int row, int size_y, char *line);
static int	is_valid_char(char c);

/*
*checks if the map contains any empty spaces or lines
*
*checks if the map is surrounded by walls
*/
int		map_check_lines(char *map, int size_y)
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
		if (ft_strchr(line, ' ') != NULL || ft_strchr(line, '\t') != NULL)
			return (FALSE);
		if (top_bottom(row, size_y, line) == FALSE || middle(row, size_y, line) == FALSE)
			return (FALSE);
		free(line);
	}
	return (TRUE);
}

/*
*checks the top and bottom row of the map
*
*checks if the rows comprise of '1' only as the top and bottom
can only be walls
*
*the bool return value is formatted that way so that
the function always returns TRUE unless the map is wrong
*
*check written notes for more
*/
static int	top_bottom(int row, int size_y, char *line)
{
	if (row == 1 || row == size_y)
	{
		while (*line && *line == '1')
			line++;
		if (*line != '\0')
			return (FALSE);		
	}
	return (TRUE);
}

/*
*checks if the start and end of the line is walls (1)
*
*checks if the line contains invalid characters
*/
static int	middle(int row, int size_y, char *line)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(line) - 1;
	if (row != 1 && row != size_y)
	{
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
	}
	return (TRUE);
}

/*
*checks if the char is 0, 1, P, C, E
*valid: 0, 1, P, C, E
*/
static int	is_valid_char(char c)
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
