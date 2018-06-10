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

int	main(int ac, char **av)
{
	struct s_sok so;

	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0)
			my_panel();
		so.buffer = open_file(av[1]);
	} else
		return (84);
	fill_struct(&so);
	check_map(&so);
	initscr();
	noecho();
	curs_set(0);
	while (my_strlen(so.map[0]) > COLS || nb_line(so.map) > LINES) {
		mvprintw(LINES / 2, (COLS / 2 - 6), "Resize");
		refresh();
	}
	clear();
	start_sokoban(&so);
	return (0);
}
