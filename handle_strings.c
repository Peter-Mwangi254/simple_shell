#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: string
 * @s2: string
 * Return: 0 when they match ,positive integer if s1 > s2
 * else negative integer if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
