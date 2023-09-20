#include "shell.h"

/**
 * non_interactive_shell - Function for non-interactive mode execution
 *
 * Return: void
 */

void non_interactive_shell(void)
{
	char *line;
	char **args;
	int status = -1;

	while (1)
	{
		line = read_stream();
		args = split_line(line);
		status = exec_builtin(args);

		/* avoid memory leaks */
		free(line);
		free(args);

		/* exit with status */
		if (status >= 0)
		{
		exit(status);
		}
	} while (status == -1);
}
