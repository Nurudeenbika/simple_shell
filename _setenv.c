#include "shell.h"
/**
 * _issetenv - finds if line input is setenv
 * @p: input of user, array of pointers
 * @myenv: copy of environmental variables
 * @loop: number of loops
 * @e: number of elements in m
 * @v: arguments
 * Return: -1 if fails or 0 if success
 */
int _issetenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	char str[] = "setenv";
	int i = 0, cont = 0, salida = -1;

	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 6)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 6)
		cont++;
	if (cont == 7)
	{
		if (p[1] != NULL && p[2] != NULL)
			_setenv(p, myenv, e, loop, v);
		else
			_put_err(p, loop, 5, v);
		salida = 0;
		currentstatus(&salida);
	}
	else if (cont == 6)
	{
		salida = 0;
		_put_err(p, loop, 3, v);
		currentstatus(&salida);
	}
	return (salida);
}
/**
 * _setenv - function to add or modify an environment variable
 * environ points to an array of pointers to strings called the "environment"
 * @myenv: icopy of environmental
 * @loop: number of loops
 * @p: input of user
 * @e: number of elements in m
 * @v: arguments
 */
void _setenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	int i, lg, j, k = 0, cont = 0, p2len = 0, myenvlen = 0;
	char *entirenv, *withequal;

	lg = _strlen(p[1]);
	withequal = str_concat(p[1], "=");
	entirenv = str_concat(withequal, p[2]);
	for (i = 0; (*myenv)[i] != NULL; i++, cont = 0)
	{
		for (j = 0; p[1][j] != '\0' && j < lg; j++)
		{
			if (p[1][j] == (*myenv)[i][j])
				cont++;
		}
		if (cont == lg)
			break;
	}
	if (cont == lg)
	{
		myenvlen = _strlen((*myenv)[i]), p2len = _strlen(p[2]);
		if (p2len < myenvlen)
		{
			for (k = 0; entirenv[k] != '\0'; k++)
				(*myenv)[i][k] = entirenv[k];
			for (; k < myenvlen; k++)
				(*myenv)[i][k] = 0;
		}
		else
		{
			(*myenv)[i] = _realloc((*myenv)[i], myenvlen, _strlen(entirenv));
			for (k = 0; entirenv[k] != '\0'; k++)
				(*myenv)[i][k] = entirenv[k];
		} free(withequal), free(entirenv), *e = *e;
	}
	else if (cont != lg && p[1] != NULL && p[2] != NULL)
	{
		_setenvcreat(myenv, e, entirenv);
		free(withequal), free(entirenv);
	}
	else
		_put_err(p, loop, 5, v);
}
/**
 * _setenvcreat - function to add or modify an environment variable
 * environ points to an array of pointers to strings called the "environment"
 * @myenv: icopy of environmental
 * @e: number of elements in m
 * @entirenv: concatenate arguments
 */
void _setenvcreat(char ***myenv, int *e, char *entirenv)
{
	int i = 0, k = 0;
	char **new = NULL;

	new = _calloc(*e + 2, sizeof(char *));
	for (i = 0; (*myenv)[i] != NULL; i++)
	{
		for (k = 0; (*myenv)[i][k]; k++)
			;
		new[i] = _calloc(k + 1, sizeof(char));
		for (k = 0; (*myenv)[i][k] != '\0'; k++)
			new[i][k] = (*myenv)[i][k];
	}
	new[i] = _calloc(_strlen(entirenv) + 1, sizeof(char));
	for (k = 0; entirenv[k] != '\0'; k++)
		new[i][k] = entirenv[k];
	new[i + 1] = NULL;
	*e = *e + 1;
	free_grid((*myenv), *e);
	(*myenv) = new;
}
