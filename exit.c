#include "shell.h"
/**
 *my_exit - function that terminates a process
 *@args: empty args
 *
 * Return: 0 on succesfull termination
 */
int my_exit(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

