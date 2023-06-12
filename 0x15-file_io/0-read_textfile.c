#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it
 * @letters: is the number of bytes to read
 * @filename: name of file to read
 *
 * Return: returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = open(filename, O_RDONLY);
	char *buffer = (char *)malloc(letters * sizeof(char));

	if (filename == NULL || letters == 0)
		return (0);
	if (fd == -1)
		return (0);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	ssize_t bytesRead = read(fd, buffer, letters);

	if (bytesRead == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	if (bytesWritten == -1 || bytesWritten != bytesRead)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	free(buffer);

	return (bytesRead);
}
