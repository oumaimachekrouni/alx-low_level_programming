#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sum variable arguments
 * @n: the number of arguments
 * @...: the integer sum
 * Return: the integer sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	va_list args;

	if (n == 0)
		return (0);

	va_start(args, n);

	for (unsigned int i = 0; i < n; i++)
	{
		int num = va_arg(args, int);

		sum += num;
	}

	va_end(args);

	return (sum);
}
