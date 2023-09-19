#include "shell.h"
/**
 * prompt_user - prints prompt message on the terminal
 *
 * Return: 0 when successful, else 1
 */
int prompt_user(void)
{
if (write(STDOUT_FILENO, "$ ", 2) == -1)
{
perror("Error writing prompt");
return (1);
}
fflush(stdout);
return (0);
}
