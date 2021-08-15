#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
* _strcat - Write a function that concatenates two strings.
* @src: source to copy string
* @dest: destiny
* Return: 0
*/

char *_strcat(char *dest, char *src)
{
	int i;
	int n;

	for (i = 0; dest[i] != '\0';)
	{
		i++;
	}

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(int ac, char *av[])
{
	int i, fd;
	char buffer[1024], *word, *delim = ";";
	char **tokens;

	for (i = 0; av[i]; i++)
	{
		_strcat(buffer, av[i]);
		_strcat(buffer, delim);
	}

	word = strtok(buffer, delim);

	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, delim);
	}

	return (0);
}
