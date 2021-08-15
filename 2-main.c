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
	char *prompt = "cuchufli% ", *line;
	int input = 0, status;
	size_t lineSize = 0;
	pid_t child_pid;
	char buffer[6] = "Hello";

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		input = getline(&line, &lineSize, stdin);
		printf("%s", buffer);

		child_pid = fork();

		if (child_pid == 0)
		{
			printf("%s", buffer);
			sleep(3);
		}
		if (child_pid == -1)
		{
			exit(98);
		}
		else
		{
			wait(&status);
			printf("%s", buffer);
		}
	}

	free(line);
	return (0);
}
