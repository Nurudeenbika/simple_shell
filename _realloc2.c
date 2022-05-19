#include "shell.h"

/**
 * _realloc2 - change the size and copy the content
 * @a: string to add
 * @p: malloc pointer to reallocate
 * @old: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size)
{
	char *pa = NULL;
	unsigned int i, j = 0;

	if (new_size == old)
		return (p);
	if (p == NULL || a == NULL)
	{
		pa = _calloc(new_size + 1, sizeof(char));
		if (!pa)
			return (NULL);
		return (pa);
	}
	while (a[j] != '\0')
		j++;
	if (new_size == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	if (new_size > old)
	{
		pa = _calloc(new_size + 1, sizeof(char));
		if (!pa)
			return (NULL);
		for (i = 0; i < j; i++)
			pa[i] = a[i];
		for (; i <= new_size; i++)
			pa[i] = *((char *)p + (i - j));
		free(p);
	}
	else
	{
		pa = _calloc(new_size, sizeof(char));
		if (!pa)
			return (NULL);
		for (i = 0; i < new_size; i++)
			pa[i] = *((char *)p + i);
		free(p);
	}
	return (pa);
}
