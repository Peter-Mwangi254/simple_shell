#include "shell.h"

/**
 * exec_built - function to execute builtin args
 * @args: command to execute
 *
 * Return: executed command
 */

int exec_built(char **args)
{
	static int cmd_num;
	char *builtin_funcs[] = {"env", "cd", "exit",};

	int (*builtin_func[])(char **) = {&env, &my_cd, &my_exit, NULL};

	size_t i = 0;


	/*check if no args was passed*/

	if (args[0] == NULL)
	{
		return (-1);
	}

	/*check if command is inbuilt*/
	for (; i < sizeof(builtin_funcs) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_funcs[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/* create a new process */
	cmd_num++;
	return (execute_cmd(args, cmd_num));
}
