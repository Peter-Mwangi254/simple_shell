#include "shell.h"

/**
 * split_line - function to tokenize input string
 * @line: string to be splitted
 *
 * Return: pointer to the first token
 */

char **split_line(char *line)
{
	int size_of_line = 64;
	int count = 0;
	char **tokens;
	char *token;

	tokens = malloc(size_of_line * sizeof(char *));

	if (tokens == NULL)
	{
		perror("memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line,DELIMETER);
	while (token != NULL)
	{

		if (token[0] == '#')
			break;
		tokens[count] = token;
		count++;

		if (count >= size_of_line)
		{
			size_of_line += size_of_line;
			tokens = realloc(tokens, size_of_line * sizeof(char));
			if (tokens == NULL)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMETER);
	}
	tokens[count] = NULL;
	return (tokens);

}
