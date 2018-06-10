/*
** EPITECH PROJECT, 2017
** color.c
** File description:
** ...
*/

#include "my.h"
#include "sok.h"

void    my_color_init(void)
{
	start_color();
	init_pair(10, COLOR_GREEN, COLOR_GREEN);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_pair(11, COLOR_YELLOW, COLOR_YELLOW);
	init_color(COLOR_YELLOW, 740, 690, 430);
	init_pair(12, COLOR_BLUE, COLOR_BLUE);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_pair(13, COLOR_BLACK, COLOR_BLACK);
	init_color(COLOR_BLACK, 1000, 1000, 1000);
	init_pair(14, COLOR_RED, COLOR_RED);
	init_color(COLOR_RED, 1000, 0, 0);
}

void    my_check_carac(char caractere, int x, int y)
{
	int     i = 0;
	char *str = " XOP#";

	while (caractere != str[i] && str[i] != '\0')
		i++;
	if (i <= 5) {
		attron(COLOR_PAIR(i + 10));
		mvaddch(y, x, caractere);
		attroff(COLOR_PAIR(i + 1));
	}
}

void    my_aff_curse(struct s_sok *so)
{
	int x = 0;
	int y = 0;

	my_color_init();
	while (so->map[y][x])
		x++;

	while (so->map[y]) {
		x = 0;
		while (so->map[y][x]) {
			my_check_carac(so->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
