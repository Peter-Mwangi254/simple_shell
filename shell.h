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
int exec_built(char **args);
int prompt_user(void);
char *find_path(char *arg);

/*non_interactive_shell*/
char *read_stream(void);

/*handle strings*/
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *str);
int _putstr(char *str, int fd);
int _putchar(char z);

/*-------BUILTIN FUNCTIONS-----*/
int my_cd(char **args);
int env(char **args);
int my_exit(char **args);

/*-------MACROS--------*/
#define DELIMETER " \t\r\n\a\""
#define PROMPT "$ "
extern int cmd_num;
extern char **environ;
extern char *prog_name;
#endif
