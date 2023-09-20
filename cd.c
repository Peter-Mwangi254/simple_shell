#include "shell.h"

/**
 * my_cd - function to changes the working directory
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int my_cd(char **args)
{

	if (args[1] == NULL)
	{
		perror("chdir");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in chdir..\n");
			return (-1);
		}
	}
	return (-1);
}
