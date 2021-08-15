#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _strlen(char *string)
{
	int i;
	while (string[i])
		i++;
	return (i);
}

int main()
{
	char *prompt = "cuchufli% ";
	char *line;
	int input = 0, status = 0;
	size_t lineSize = 0;
	pid_t child_pid;
	char *program = "ls";
	char *parameters = NULL;
	char buffer[2] = "He";

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
		child_pid = fork();

		if (strcmp(program, line) == 0)

			if (child_pid == 0)
				printf("%s", buffer);
			else
				wait();
		// execve("/bin/ls", &program, environ);

		// write(STDOUT_FILENO, line, input);
	}

	free(line);
	return (0);
}
