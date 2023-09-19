#ifndef _SHELL_H_
#define _SHELL_H_

/* my header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*------PROTOTYPES--------*/
void interactive_shell(void);
void non_interactive_shell(void);

/*interactive_shell.c*/
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int prompt_user(void);

/*non_interactive_shell*/
char *read_stream(void);
#endif
