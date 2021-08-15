#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int _strlen(char *string)
{
	int i;
	while (string[i])
		i++;
	return (i);
}

int main()
{
	char *prompt = "$ ";
	char *line;
	int input = 0;
	size_t lineSize = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		input = getline(&line, &lineSize, stdin);

		/* Si getline falla se libera line y termina el programa */
		if (input == -1)
		{
			free(line);
			return (0);
		}

		write(STDOUT_FILENO, line, input);
	}
	free(line);
	return (0);
}
