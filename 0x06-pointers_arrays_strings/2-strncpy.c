#include "main.h"

/**
 * *_strncpy - copy a string
 *
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * @n: Maximum number of bytes to be copied from source
 *
 * Return: Pointer to the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
