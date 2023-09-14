#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_isalpha - checks for alphabetic character
 *@k: The character to input
 *Return: 1 if k is alphabetic, 0 otherwise
 */

int _isalpha(int k)

{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);

	else
		return (0);
	}

/**
 * is_delim - checks if character is a delimeter
 * @k: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char k, char *delim)
{
	while (*delim)
		if (*delim++ == k)
			return (1);
	return (0);
}

/**
 *_atoi - converts a string to an integer
 *@t: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *t)
{
	int f, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (f = 0;  t[f] != '\0' && flag != 2; f++)
	{
		if (t[f] == '-')
			sign *= -1;

		if (t[f] >= '0' && t[f] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[f] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
