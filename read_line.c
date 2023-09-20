#include "shell.h"
/**
 * read_line - reads input from the user
 *
 * Return: returns pointer to user input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	size_t len;

	if (getline(&line, &buffsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	len = _strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
	return (line);
}
