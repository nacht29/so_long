#include "../../includes/so_long.h"

static int	check_elements(t_map *elements);

/*
*checks if the map is composed if the right elements:
0, 1, P, C, E
*
*checks if the map contains the right amout of each element:
P and E = 1, C >= 1
*/
int	map_check_elem(char *map, int size_y)
{
	int				fd;
	int				row;
	int				status;
	char			*line;
	static t_map	*elements;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	elements = malloc(sizeof(t_map));
	if (elements == NULL)
		return (FALSE);
	init_elem_stuct(&elements);
	row = 0;
	while (++row <= size_y)
	{
		line = get_next_line(fd);
		count_elements(&elements, line);
		free(line);
	}
	status = check_elements(elements);
	free(elements);
	return (status);
}

/*
*initiates element struct
*/
void	init_elem_stuct(t_map **elements)
{
	(*elements)->player_count = 0;
	(*elements)->item_count = 0;
	(*elements)->exit_count = 0;
}

/*
*count the number of each element present in the map
*
*will be used in flood_fill to see if exit and collectibles are
accessible
*
*e.g. collectibles reached vs total num of collectibles
*/
void	count_elements(t_map **elements, char *line)
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

/*
*checks if the map contains the right amout of each element:
P and E = 1, C >= 1
*/
static int	check_elements(t_map *elements)
{
	if (elements->player_count != 1 || elements->exit_count != 1)
		return (FALSE);
	if (elements->item_count < 1)
		return (FALSE);
}
