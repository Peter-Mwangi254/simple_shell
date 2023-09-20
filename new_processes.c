#include "shell.h"

/**
 * execute_cmd - Function that executes command
 * @args: command to execute
 * @cmd_num: comand number
 * Return: 1 if success, 0 otherwise
 */
int execute_cmd(char **args, int cmd_num)
{
	pid_t child_pid;
	int exe, status;
	char *cmd, *av,  *prog_name = "./hsh";

	if (args != NULL)
	{
		cmd = args[0];
		av = find_path(cmd);
		if (av == NULL)
		{
		print_err(cmd_num, prog_name);
			_putstr(args[0], STDERR_FILENO);
			_putstr(": not found\n", STDERR_FILENO);
			return (127);
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			exe = execve(av, args, environ);
			if (exe == -1)
			{
				print_err(cmd_num, prog_name);
				_putstr(strerror(errno), STDERR_FILENO);
				write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
			}
		}
		else if (child_pid < 0)
			perror("fork failed");
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		if (av != cmd)
			free(av);
		return (-1);
	}
	return (0);
}
