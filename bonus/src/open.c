/*
** EPITECH PROJECT, 2017
** open
** File description:
** ...
*/

#include "my.h"
#include "sok.h"

char	*open_file(char *name)
{
	FILE	*fd = fopen(name, "r");
	ssize_t	read;
	size_t	len;
	char	*buffer = NULL;
	char	*final = "\n";

	if (fd == NULL)
		exit(84);
	while ((read = getline(&buffer, &len, fd)) != -1) {
		final = my_strcat(final, buffer);
	}
	return (final);
}
