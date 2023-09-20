#include"shell.h"
/**
 * print_num - function to print integer
 * @n: Number to print
 * Return: number of byte
 */

int print_num(unsigned int n)
{
	int count = 0, num_byte, i;
	unsigned int temp = n;
	char *arr;

	if (n == 0)
	{
		write(STDERR_FILENO, "0", 1);
		return (1);
	}
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	arr = malloc(count + 1);
	if (arr == NULL)
	{
		perror("Allocation failed");
		exit(EXIT_FAILURE);
	}

	i = count - 1;
	while (n > 0)
	{
		arr[i--] = '0' + (n % 10);
		n /= 10;
	}
	num_byte = write(STDERR_FILENO, arr, count);
	free(arr);

	return (num_byte);
}

/**
 * print_err - Function to print error message
 * @cmd_no: command number
 * @prog_name: Program name
 */
void print_err(int cmd_no, char *prog_name)
{
	_putstr(prog_name, STDERR_FILENO);
	_putstr(": ", STDERR_FILENO);
	print_num(cmd_no);
	_putstr(": ", STDERR_FILENO);
}
