#include "shell.h"
#include <limits.h>

/**
 *_type - get the type of exit
 * @p: input user, array of pointers
 * @L: counter of loops
 * @l: input user
 * @i: number of pointers inside the array of pointers
 * @v: arguments in input
 * @m: copy of environmental variables
 * @e: number of elements in m
 * @f: input complete
 */
void _type(char **p, int L, char *l, int i, char **v, char **m, int e, char *f)
{
	unsigned int  c = 0, flag = 0;
	long int valor = 0;

	if (p[1] == NULL || (p[1][0] == '0' && p[1][1] == '\0'))
	{
		free(l), free(f), free_grid(p, i), free_grid(m, e);
		exit(currentstatus(NULL));
	}
	else
	{
		while (p[1][c] != '\0')
		{
			if ((p[1][0] != '+' && p[1][0] != '-') &&
			    (p[1][c] < 48 || p[1][c] > 57))
			{
				flag = 1;
				break;
			}
			c++;
		}
		if (flag == 1)
			_put_err(p, L, 1, v);
		else
		{ valor = _atoi(p[1]);
			if (!(valor > INT_MAX) && valor > 0)
			{
				valor = valor % 256;
				free(l), free(f), free_grid(p, i);
				free_grid(m, e), exit(valor);
			}
			else if (valor < 0)
			{
				_put_err(p, L, 1, v);
				free(l), free(f), free_grid(p, i);
				free_grid(m, e), exit(2);
			}
			else
				_put_err(p, L, 1, v);
		}
	}
}
/**
 * _isexit - finds if line input is exit therefore process termination
 * @p: input of user, array of pointers
 * @L: loop counter
 * @l: input user
 * @v: arguments in input
 * @m: copy of environmental variables
 * @f: complet input
 * Return: -1 if there is no exit or 0 if there is the word exit
 */
int _isexit(char **p, int L, char *l, char **v, char **m, char *f)
{
	char str[] = "exit";
	int i, cont = 0, salida = -1, x = 0, e = 0;

	for (x = 0; p[x] != NULL; x++)
		;
	for (e = 0; m[e] != NULL; e++)
		;
	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 4)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 4)
		cont++;

	if (cont == 5)
	{
		_type(p, L, l, x, v, m, e, f);
		salida = 0;
	}
	else if (cont == 4)
	{
		salida = 0;
		_put_err(p, L, 3, v);
	}
	return (salida);
}
