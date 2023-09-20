#include "shell.h"
/**
 * interactive_shell - function that handles commands from command line
 * Return: void
 */
void interactive_shell(void)
{
	char *line;
	char **args;
	int status = -1;
while (1)
{
	prompt_user();
	line = read_line();
	args = split_line(line);
	status = exec_builtin(args);
	free(line);
	free(args);
	if (status >= 0)
	{
		exit(status);
	}
} while (status == -1);
}








