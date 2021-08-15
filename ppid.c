#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	/* GET PARENT PROCCESS ID */
	my_pid = getppid();
	printf("Parent process id -> %u\n", my_pid);

	return (0);
}
