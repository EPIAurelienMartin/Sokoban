/*
** EPITECH PROJECT, 2017
** open
** File description:
** file
*/

#include "my.h"

int     file_exist(char *file)
{
	int   fd;

	if (-1 == (fd = open(file, O_RDONLY))) {
		my_putstr("File doesn't exist !\n");
		return (-1);
	}
	return (fd);
}

char    *open_my_file(char *name)
{
	int   fd;
	char  *buffer;
	int   size;
	struct stat st;

	if (stat(name, &st) == -1)
		return (NULL);
	size = st.st_size;
	if ((buffer = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	fd = file_exist(name);
	if (read(fd, buffer, size) == -1)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	buffer[size] = '\0';
	return (buffer);
}
