/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "sok.h"

void	my_panel(void)
{
	my_printf("USAGE\n\t\t./my_sokoban map\n\nDESCRIPTION\n");
	my_printf("\t\tmap\tfile representing the warehouse map, containing ");
	my_putstr("'#' for walls,\n");
	my_printf("\t\t\t'P' for the player, 'X' for boxes and 'O' for ");
	my_putstr("storage locations.\n");
	exit (0);
}

void	my_level(struct s_sok *so)
{
	so->level = my_str_to_word_array(".", "\n");
	so->level[0] = my_strdup("map/level1");
	so->level[1] = my_strdup("map/level2");
	so->level[2] = my_strdup("map/level3");
	so->level[3] = my_strdup("map/level4");
	so->level[4] = my_strdup("map/level5");
	so->level[5] = my_strdup("map/level6");
	so->level[6] = NULL;
}

void	for_level(struct s_sok *so)
{
	int	i = 0;

	my_level(so);
	while (so->level[i] != NULL) {
		so->buffer = open_file(so->level[i]);
		fill_struct(so);
		check_map(so);
		initscr();
		noecho();
		curs_set(0);
		while (my_strlen(so->map[0]) > COLS || nbl(so->map) > LINES) {
			mvprintw(LINES / 2, (COLS / 2 - 6), "Map too big.");
			refresh();
		}
		clear();
		start_sokoban(so);
		i++;
	}
	clear();
	endwin();
	exit(1);
}

int	main(int ac, char **av)
{
	struct s_sok so;

	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0)
			my_panel();
	} else
		for_level(&so);
	return (0);
}
