#include "shell.h"

/**
 * _strdup - Duplicate a string using malloc
 * @str: string to duplicate
 * Return: Pointer to a the new duped string
 */

char *_strdup(char *str)
{
	char *a;
	int i, c;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	a = malloc(i * sizeof(*a) + 1);
	if (a == NULL)
		return (NULL);

	for (c = 0; c < i; c++)
		a[c] = str[c];
	a[c] = '\0';

	return (a);
}
/**
 * _strlen - calculates the length of a string
 * @str: string to be calculated
 * Return: length of string
 */

int _strlen(char *str)
{
if (*str == '\0')
	return (0);
else
	return (1 + _strlen(str + 1));
}

/**
 * _putchar - Function that prints character
 * @z: character to print
 * Return: character printed
 */

int _putchar(char z)
{
	return (write(1, &z, 1));
}

/**
 * _putstr - Function to print string
 * @str: string to print
 * @fd: file descriptor
 * Return: Number of strings printed
 */

int _putstr(char *str, int fd)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		count += 1;
		i++;
	}
	return (count);
}
