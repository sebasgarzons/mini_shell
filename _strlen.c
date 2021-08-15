#include "main.h"

/**
 * _strelen - function that counts letters in array
 * @string: string to evaluate
 * Return: return letter counts
 */

int _strlen(char *string)
{
	int i = 0;
	while (string[i])
		i++;
	return (i);
}
