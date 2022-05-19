#include "shell.h"
/**
 * _updatepwd - change the OLDPWD env variable
 * @buf: pointer to old pwd
 * @myenv: copy of environmental variable
 * Return: the string inside PWD env variable
 */
void _updatepwd(char *buf, char **myenv)
{
	char *entirepwd;
	char str[] = "PWD=";
	int i = 0, j = 0, cont = 0, k = 0, myenvlen = 0, buflen = 0;

	entirepwd = str_concat(str, buf);
	for (i = 0; myenv[i] != NULL; i++, cont = 0)
	{
		for (j = 0; myenv[i][j] != '\0' && j < 4; j++)
		{
			if (myenv[i][j] == str[j])
			{
				cont++;
			}
			else
				break;
		}
		if (cont == 4)
			break;
	}
	if (cont == 4)
	{
		myenvlen = _strlen(myenv[i]);
		buflen = _strlen(entirepwd);
		if (buflen < myenvlen)
		{
			for (k = 0; entirepwd[k] != '\0'; k++)
				myenv[i][k] = entirepwd[k];
			for (; k < myenvlen; k++)
				myenv[i][k] = 0;
		}
		else
		{
			myenv[i] = _realloc(myenv[i], myenvlen, buflen + 1);
			for (k = 0; entirepwd[k] != '\0'; k++)
				myenv[i][k] = entirepwd[k];
		}
	}
	free(entirepwd);
}
/**
 * _updateoldpwd - change the OLDPWD env variable
 * @buf: pointer to old pwd
 * @myenv: copy of environmental variable
 * Return: the string inside PWD env variable
 */
void _updateoldpwd(char *buf, char **myenv)
{
	char *entirepwd;
	char str[] = "OLDPWD=";
	int i = 0, j = 0, cont = 0, k = 0, myenvlen = 0, buflen = 0;

	entirepwd = str_concat(str, buf);
	for (i = 0; myenv[i] != NULL; i++)
	{
		for (j = 0; myenv[i][j] != '\0' && j < 7; j++)
		{
			if (myenv[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 7)
			break;
	}
	if (cont == 7)
	{
		myenvlen = _strlen(myenv[i]);
		buflen = _strlen(entirepwd);
		if (buflen < myenvlen)
		{
			for (k = 0; entirepwd[k] != '\0'; k++)
				myenv[i][k] = entirepwd[k];
			for (; k < myenvlen; k++)
				myenv[i][k] = 0;
		}
		else
		{
			myenv[i] = _realloc(myenv[i], myenvlen, buflen + 1);
			for (k = 0; entirepwd[k] != '\0'; k++)
				myenv[i][k] = entirepwd[k];
		}
	}
	free(entirepwd);
}
