#include "../../includes/so_long.h"

static void	count_elements(t_map **elements, char *line);
static void	init_stuct(t_map **elements);
static int	check_elements(t_map *elements);

int	map_check_elem(char *map, int size_y)
{
	int		fd;
	int		row;
	char	*line;
	static t_map	*elements;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	elements = malloc(sizeof(t_map));
	if (elements == NULL)
		return (FALSE);
	init_stuct(&elements);
	row = 0;
	while (++row <= size_y)
	{
		line = get_next_line(fd);
		count_elements(&elements, line);
		free(line);
	}
	return (check_elements(elements));
}

static void	init_stuct(t_map **elements)
{
	(*elements)->player_count = 0;
	(*elements)->item_count = 0;
	(*elements)->exit_count = 0;
}

static void	count_elements(t_map **elements, char *line)
{
	while (*line)
	{
		if (*line == 'P')
			(*elements)->player_count++;
		else if (*line == 'C')
			(*elements)->item_count++;
		else if (*line == 'E')
			(*elements)->exit_count++;
		line++;
	}
}

static int	check_elements(t_map *elements)
{
	if (elements->player_count != 1 || elements->exit_count != 1)
		return (FALSE);
	if (elements->item_count < 1)
		return (FALSE);
}
