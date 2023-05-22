#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * _strlen - a function that gets a length of string
 * @str: the string to get the length
 * Return: length of @str
 */
int _strlen(const char *str)
{
	int length = 0;

	while (*str++)
		length++;
	return (length);
}
/**
 * _strcopy - a function that returns @dest with a copy of a string from @src
 * @src: string to copy
 * @dest: copy string to here
 * Return: @dest
 */
char *_strcopy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * new_dog - creates a new dog
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int nameLen, ownerLen;

	/* Check if name and owner are empty*/
	if (name == NULL || owner == NULL)
		return (NULL);

	/* Calculate the lengths of name and owner */
	nameLen = strlen(name);
	ownerLen = strlen(owner);

	/* Allocate memory for the dog */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Allocate memory for the name and copy it */
	dog->name = malloc(sizeof(char) * (nameLen + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	strcpy(dog->name, name);

	/* Allocate memory for the owner and copy it */
	dog->owner = malloc(sizeof(char) * (ownerLen + 1));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	strcpy(dog->owner, owner);

	/* Set the age */
	dog->age = age;

	return (dog);
}
