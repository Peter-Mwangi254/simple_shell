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



#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2













/* my prototypes*/

/* task0.c prototypes*/
int interactive(info_t *);
int is_mwangi(char, char *);
int _naya(int);
int _my_special_aggy(char *);
















#endif
