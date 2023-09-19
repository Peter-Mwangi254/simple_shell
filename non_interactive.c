#include "shell.h"

/**
 * non_interactive_mode - Function for non-interactive mode execution
 *
 * Return: void
 */

void non_interactive_mode(void)
{
	char *buffer;
	char **args;
	int status = -1;

	while (1)
	{
		buffer = read_line();
		args = tokenize(buffer);
		status = exec_builtin(args);

		/* avoid memory leaks */
		free(buffer);
		free(args);

		/* exit with status */
		if (status >= 0)
		{
		exit(status);
		}
	} while (status == -1);
}
