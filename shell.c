#include "shell.h"
/**
 * main - entry point
 * Return: returns 0 when successful and -1 when unsuccessful
 */

int main(void)
{
	int fd = 1;

	if (isatty(fd))
	{
		interactive_shell();
	}
	else
	{
		non_interactive_shell();
	}
	return (0);
}
