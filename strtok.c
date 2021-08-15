#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* _strcat - Write a function that concatenates two strings.
* @src: source to copy string
* @dest: destiny
* Return: 0
*/

extern char **environ;

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

char **splits(char **av)
{

	int i;
	char buffer[1024], *word, *delim = ";";
	char **tokens;

	for (i = 0; av[i]; i++)
	{
		_strcat(buffer, av[i]);
		_strcat(buffer, delim);
	}
	tokens = malloc(sizeof(char *) * i);
	if (tokens == NULL)
	{
		free(tokens);
		return (0);
	}
	word = strtok(buffer, delim);

	for (i = 0; av[i]; i++)
	{
		tokens[i] = malloc(sizeof(char *));
		if (tokens[i] == NULL)
			return (0);
		tokens[i] = strtok(NULL, delim);
	}
	printf("");
	return (tokens);
}

int main(int ac, char **av)
{
	int i = 0;
	char **loquesea;

	loquesea = splits(av);

	for (i = 0; loquesea[i]; i++)
	{
		printf("arrays -> %s\n", loquesea[i]);
	}

	free(loquesea);
	return (0);
}
