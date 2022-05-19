#include "shell.h"

/**
 * salida3 - normal out
 * @m: copy of environmental variables
 * @e: number of elements in m
 */
void salida3(char **m, int e)
{
	free_grid(m, e);
	exit(currentstatus(NULL));
}
/**
 * salida2 - out with double Ctrl+D
 *@m: copy of environmental variables
 *@e: number of elements in m
 *@line: input of user
 */
void salida2(char **m, int e, char *line)
{
	free(line);
	free_grid(m, e);
	write(STDIN_FILENO, "#cisfun$ ", 9);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}
/**
 * salida1 - normal out
 * @m: copy of environmental variables
 * @e: number of elements in m
 */
void salida1(char **m, int e)
{
	free_grid(m, e);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}
/**
 * _getline - function to read what the user writes
 * @a: pointer to loop counter
 * @e: length of m
 * @m: copy of environmental
 * Return: line in sucess otherwise NULL.
 */
char  *_getline(int *a, char **m, int e)
{
	char letter[1] = {0}, *line = NULL;
	size_t bufsize = 0;
	static int num = 1;

	if (num == 2)
	salida2(m, e, line);
	for (; (num != 0); bufsize = 0, free(line))
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		*a = *a + 1;
		signal(SIGINT, _signal);
		for (; ((num = read(STDIN_FILENO, letter, 1)) > 0); bufsize++)
		{
			if (bufsize == 0)
				line = _calloc(bufsize + 3, sizeof(char));
			else
				line = _realloc(line, bufsize, bufsize + 3);
			if (!line)
			{
				num = 0;
				break;
			}
			line[bufsize] = letter[0], line[bufsize + 1] = '\n';
			line[bufsize + 2] = '\0';
			if (line[bufsize] == '\n')
				break;
		}
		if (num == 0 && bufsize == 0)
			break;
		else if (num == 0 && bufsize != 0)
		{
			num = 2;
			break;
		}
		else if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
		salida1(m, e);
	return (line);
}
/**
 * _getlineav - function to read what the user writes
 * @a: pointer to loop counter
 * @e: length of m
 * @m: copy of environmental
 * @av: arguments in input
 * Return: line in sucess otherwise NULL.
 */
char  *_getlineav(int *a, char **m, int e, char **av)
{
	char letter[1] = {0}, *li = NULL;
	size_t bz = 0;
	static unsigned int num = 1;
	static int  fd;

	for (; (num != 0); bz = 0, free(li))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{ close(fd), free_grid(m, e);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": 0: ", 5);
			write(STDERR_FILENO, "Can't open ", 11);
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1), exit(127);
		}
		*a = *a + 1;
		while ((num = read(fd, letter, 1)) > 0)
		{
			if (bz == 0)
				li = _calloc(bz + 3, sizeof(char));
			else
				li = _realloc(li, bz, bz + 3);
			if (!li)
			{
				num = 0;
				break;
			}
			li[bz] = letter[0], li[bz + 1] = '\n';
			li[bz + 2] = '\0', bz++;
		}
		if (num == 0 && bz == 0)
			break;
		else if (li[0] != '\n')
			return (li);
	}
	if (num == 0)
		close(fd), salida3(m, e);
	return (li);
}
