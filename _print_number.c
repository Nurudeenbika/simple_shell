#include "shell.h"

/**
 * print_number - prints all natural numbers
 * @n: parameter to print
 * Return: Always 0
 */
void print_number(int n)
{
	unsigned int j, cont = 1;
	char a;
	unsigned int var1, num, var2, var3 = 1;

	var2 = n;
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		cont++;
		var3 = var3 * 10;
	}
	for (j = 1; j <= cont; j++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		a = '0' + var1;
		write(STDERR_FILENO, &a, 1);
	}
}
