#include "main.h"
#include <stdlib.h>
/**
 * *_strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: string
 * Return: 0
 */
char *_strdup(char *str)
{
	int i = 0, size = 0;
	char *m;

	if (str == NULL)
		return (NULL);

	for (; str[size] != '\0'; size++)
	;
	/*+1 on the size puts the end of string character*/
	m = malloc((size + 1) * sizeof(*str));

	if (m == NULL)
		return (NULL);

	for (; i < size; i++)
		m[i] = str[i];
	m[i] = '\0'; /* Add the null-terminating character at the end*/
	return (m);
}
