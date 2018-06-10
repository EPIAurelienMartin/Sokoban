/*
** EPITECH PROJECT, 2017
** start
** File description:
** sokoban
*/

#include "my.h"
#include "sok.h"

void    start_sokoban(struct s_sok *so)
{
	int     input = 0;

	my_aff_curse(so);
	initscr();
	noecho();
	curs_set(0);
	while (check_win(so) != 0) {
		input = getch();
		if (input == 'a')
			break;
		my_move(so, input);
		my_aff_curse(so);
		refresh();
		if (check_loose(so->map) == 0) {
			break;
		}
	}
	clear();
}

void    change_carac(struct s_sok *so, int y, int x)
{
	if (so->origin[y][x] == 'X' || so->origin[y][x] == 'P')
		so->origin[y][x] = ' ';
}

void    little_modif(struct s_sok *so)
{
	int     y = 0;
	int     x = 0;

	while (so->origin[y] != NULL) {
		x = 0;
		while (so->origin[y][x]) {
			change_carac(so, y, x);
			x++;
		}
		y++;
	}
	so->tp = 0;
}

void    fill_struct(struct s_sok *so)
{
	int     y = 0;
	int     x = 0;

	so->y = 0;
	so->x = 0;
	so->origin = my_str_to_word_array(so->buffer, "\n");
	so->map = my_str_to_word_array(so->buffer, "\n");
	while (so->map[y] != NULL) {
		for (x = 0 ; so->map[y][x] && so->map[y][x] != 'P' ; x++);
		if (so->map[y][x] == 'P') {
			so->y = y;
			so->x = x;
			break;
		}
		y++;
	}
	if (so->y == 0 || so->x == 0)
		exit(84);
	so->savey = so->y;
	so->savex = so->x;
	little_modif(so);
}
