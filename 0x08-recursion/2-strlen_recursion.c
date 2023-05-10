#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: pointer to the striing
 * Return: int
 */

int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s > '\0')
	{
		i += _strlen_recursion(s + 1) + 1;
	}

	return (i);
}
