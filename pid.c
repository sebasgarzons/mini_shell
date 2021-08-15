#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;

	/* GET PROCCESS ID */
	my_pid = getpid();
	printf("Process id -> %u\n", my_pid);

	return (0);
}
