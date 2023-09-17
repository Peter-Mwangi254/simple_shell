#include "shell.h"
/**
 * interactive_shell - function that handles commands from command line
 * @line : 
void interactive_shell(void)
{
    char *line;
    char **args;
    int status;
while (1)
{
    prompt_user();
    line = read_line();
    args = split_line(line);
    status = execute_args(args);
    free (line);
    free(args);
    if (status >= 0)
    {
        exit(status);
    }

}
while (status == -1);
}
