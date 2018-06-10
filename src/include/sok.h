/*
** EPITECH PROJECT, 2017
** soko
** File description:
** ban
*/

#ifndef SOK_H_
# define SOK_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"

#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define SPACE 32

struct s_sok
{
	char	*buffer;
	char	**origin;
	char	**map;
	int	y;
	int	savey;
	int	x;
	int	savex;
};

void    move_right(struct s_sok *so);
void    move_left(struct s_sok *so);
void    move_up(struct s_sok *so);
void    move_down(struct s_sok *so);
void    my_move(struct s_sok *so, int input);
int     check_win(struct s_sok *so);
int     is_block(char **tab, int y, int x);
int     check_loose(char **tab);
void    check_map(struct s_sok *so);
int     nb_line(char **tab);
void    fill_struct(struct s_sok *so);
void    little_modif(struct s_sok *so);
void    change_carac(struct s_sok *so, int y, int x);
void    start_sokoban(struct s_sok *so);
void    my_aff_curse(struct s_sok *so);
char	*open_file(char *name);
int     check_is_oo(int y, int x, struct s_sok *so);

#endif
