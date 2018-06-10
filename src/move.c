/*
** EPITECH PROJECT, 2017
** move
** File description:
** ...
*/

#include "my.h"
#include "sok.h"

void    move_right(struct s_sok *so)
{
	int	y = so->y;
	int	x = so->x;

	if ((so->map[y][x + 1] == 'X' && so->map[y][x + 2] == ' ') ||
		(so->map[y][x + 1] == 'X' && so->map[y][x + 2] == 'O')) {
		so->map[y][x] = so->origin[y][x];
		so->x += 1;
		x += 1;
		so->map[y][x] = 'P';
		so->map[y][x + 1] = 'X';
	} else if (so->map[y][x + 1] == ' ' || so->map[y][x + 1] == 'O') {
		so->map[y][x] = so->origin[y][x];
		so->x += 1;
		x += 1;
		so->map[y][x] = 'P';
	}
}

void    move_left(struct s_sok *so)
{
	int	y = so->y;
	int	x = so->x;

	if ((so->map[y][x - 1] == 'X' && so->map[y][x - 2] == ' ') ||
		(so->map[y][x - 1] == 'X' && so->map[y][x - 2] == 'O')) {
		so->map[y][x] = so->origin[y][x];
		so->x -= 1;
		x -= 1;
		so->map[y][x] = 'P';
		so->map[y][x - 1] = 'X';
	} else if (so->map[y][x - 1] == ' ' || so->map[y][x - 1] == 'O') {
		so->map[y][x] = so->origin[y][x];
		so->x -= 1;
		x -= 1;
		so->map[y][x] = 'P';
	}
}

void    move_up(struct s_sok *so)
{
	int	y = so->y;
	int	x = so->x;

	if ((so->map[y - 1][x] == 'X' && so->map[y - 2][x] == ' ') ||
		(so->map[y - 1][x] == 'X' && so->map[y - 2][x] == 'O')) {
		so->map[y][x] = so->origin[y][x];
		so->y -= 1;
		y -= 1;
		so->map[y][x] = 'P';
		so->map[y - 1][x] = 'X';
	} else if (so->map[y - 1][x] == ' ' || so->map[y - 1][x] == 'O') {
		so->map[y][x] = so->origin[y][x];
		so->y -= 1;
		y -= 1;
		so->map[y][x] = 'P';
	}
}

void    move_down(struct s_sok *so)
{
	int	y = so->y;
	int	x = so->x;

	if ((so->map[y + 1][x] == 'X' && so->map[y + 2][x] == ' ') ||
		(so->map[y + 1][x] == 'X' && so->map[y + 2][x] == 'O')) {
		so->map[y][x] = so->origin[y][x];
		so->y += 1;
		y += 1;
		so->map[y][x] = 'P';
		so->map[y + 1][x] = 'X';
	} else if (so->map[y + 1][x] == ' ' || so->map[y + 1][x] == 'O') {
		so->map[y][x] = so->origin[y][x];
		so->y += 1;
		y += 1;
		so->map[y][x] = 'P';
	}
}

void    my_move(struct s_sok *so, int input)
{
	if (input == RIGHT && so->map[so->y][so->x + 1] != '#')
		move_right(so);
	else if (input == LEFT && so->map[so->y][so->x - 1] != '#')
		move_left(so);
	else {
		if (input == UP && so->map[so->y - 1][so->x] != '#')
			move_up(so);
		else if (input == DOWN && so->map[so->y + 1][so->x] != '#')
			move_down(so);
	}
	if (input == SPACE ) {
		so->map = my_str_to_word_array(so->buffer, "\n");
		so->y = so->savey;
		so->x = so->savex;
	}
}
