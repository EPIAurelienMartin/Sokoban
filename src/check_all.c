/*
** EPITECH PROJECT, 2017
** check
** File description:
** winloose...
*/

#include "my.h"
#include "sok.h"

int     check_win(struct s_sok *so)
{
	int     y = 0;
	int     x = 0;
	int     cpt = 0;

	while (so->origin[y] != NULL) {
		x = 0;
		while (so->origin[y][x]) {
			so->map[y][x] == 'O' ? cpt++ : cpt;
			x++;
		}
		y++;
	}
	so->origin[so->y][so->x] == 'O' ? cpt ++ : cpt;
	return (cpt);
}

int     is_block(char **tab, int y, int x)
{
	int     error = 0;

	if (tab[y][x + 1] == '#' && tab[y - 1][x] == '#')
		error += 1;
	if (tab[y][x + 1] == '#' && tab[y + 1][x] == '#')
		error += 1;
	if (tab[y][x - 1] == '#' && tab[y - 1][x] == '#')
		error += 1;
	if (tab[y][x - 1] == '#' && tab[y + 1][x] == '#')
		error += 1;
	return (error);
}

int     check_loose(char **tab)
{
	int     y = 0;
	int     x = 0;
	int     er = 0;
	int     nb = 0;

	for (y = 0 ; (tab[y] != NULL) ; y++) {
		for (x = 0 ; (tab[y][x]) ; x++)
			tab[y][x] == 'X' ? nb++ : 0;
	}
	for (y = 1 ; (tab[y] != NULL) ; y++) {
		for (x = 1; (tab[y][x]) ; x++) {
			tab[y][x] == 'X' && is_block(tab, y, x) >= 1 ? er++ : 0;
		}
	}
	if (er == nb)
		return (0);
	return (84);
}

void    check_map(struct s_sok *so)
{
	int     i = 0;
	int     nb_x = 0;
	int     nb_o = 0;
	int	nb_p = 0;

	while (so->buffer[i]) {
		so->buffer[i] == 'X' ? nb_x++ : 0;
		so->buffer[i] == 'O' ? nb_o++ : 0;
		so->buffer[i] == 'P' ? nb_p++ : 0;
		if (so->buffer[i] != '#' && so->buffer[i] != ' ' &&
			so->buffer[i] != '\n' && so->buffer[i] != 'X' &&
			so->buffer[i] != 'O' && so->buffer[i] != 'P')
			exit(84);
		i++;
	}
	if (nb_x < nb_o)
		exit(84);
	if (nb_x == 0 || nb_o == 0)
		exit(1);
	if (nb_p != 1)
		exit (84);
}

int     nb_line(char **tab)
{
	int     y = 0;

	while (tab[y])
		y++;
	return (y - 1);
}
