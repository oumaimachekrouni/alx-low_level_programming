#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: starting int
 * @max: max int
 *
 * Return: array of integers
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min++;

	return (arr);
}
