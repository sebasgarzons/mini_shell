/**## LIBRARIES*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <linux/limits.h>
#include <sys/stat.h>

/**##Var of the Enviroment */
extern char **environ;

/* Integer to ASCII for signed decimal integers. */

static int next;
static char qbuf[8];

/**##Var MAKROS recordar recomendacion de prototypo es en UPPERCASE*/
#define _PRINT(c) write(STDOUT_FILENO, c, strlen(c))
#define BUFFSIZE 1024
#define DELIMITS "\t\r\a\n"

/** STRUCTS*/
typedef struct constructor
{
	char *command;
	int (*func)(char **va_list, int error);
} const_t;

typedef struct pid_Father
{
	char *text;
	char *file;
	char *name_command;
	pid_t pid;
	char *text_pid;
	struct pid_Father *next;

} pid_Father_t;

typedef struct pid_Son
{
	char *text;
	char *file;
	char *name_command;
	pid_t pid;
	char *text_pid;
	struct pid_Son *next;
} pid_Son_t;

typedef struct __pids_t
{
	pid_Father_t **pid_p;
	pid_Son_t **pid_s;
} _pids_t;

/**                    PROTOTYPES                    **/

/** STRING_FUNCTIONS**/
char *_itoa(int n);
char **_parsed(char **input);
int append_new_process(const char *filename, char *text_content, char *text_content1);
void prompter();
void signal_line(int signal);
int history(char *input);
int pids_Son(char *cmd);
void free_env(char **env);
int builder_handling(char **command, int status_er);
int lenR(char *str, int counter);
int len(char *str);
int get_process();
int check_builder(char **command);

/** **********************************************************************
 * 
 *                      FUNCTION PROMPTER
 * 
 *  **********************************************************************                      
*/
void prompter()
{
	_PRINT("$");
}

void signal_line(int signal)
{
	if (signal == SIGINT)
	{
		_PRINT("\n$");
	}
}

/** **********************************************************************
 * 
 *                      FUNCTIONS HISTORYS
 * 
 *  **********************************************************************                      
*/

int append_new_process(const char *filename, char *text_content, char *text_content1)
{
	int o, w, w2, len = 0, len1 = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	if (text_content1 != NULL)
	{
		for (len1 = 0; text_content1[len1];)
			len1++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w2 = write(o, text_content1, len1);
	w = write(o, text_content, len);

	if (o == -1 || w == -1 || w2 == -1)
		return (-1);

	close(o);

	return (1);
}

int get_process()
{

	pid_Father_t my_ppid;
	pid_Son_t my_pid;
	ssize_t _fd_tops, append_my_pids;

	my_ppid.file = "Process.tmp";
	my_pid.file = "Process.tmp";

	my_ppid.text = "Process Father ----> \t\t\t\t";
	my_pid.text = "Process son ----> \t\t\t\t";

	if (!my_ppid.file || !my_pid.file)
		return (-1);

	my_ppid.pid = getppid();
	if (my_ppid.pid != 0)
	{
		_fd_tops = open(my_ppid.file, O_CREAT | O_RDWR, 0664);
		if (_fd_tops < 0)
			return (99);

		my_ppid.text_pid = _itoa(my_ppid.pid);
		if (my_ppid.text_pid != NULL)
		{
			append_new_process(my_ppid.file, my_ppid.text_pid, my_ppid.text);
		}
	}

	my_pid.pid = getpid();
	if (my_pid.pid != 0)
	{
		my_pid.text_pid = _itoa(my_pid.pid);
		if (my_pid.text_pid != NULL)
		{
			append_my_pids = append_new_process(my_pid.file, my_pid.text_pid, my_pid.text);
		}
	}

	close(_fd_tops);

	(void)append_my_pids;
	return (0);
}

int pids_Son(char *cmd)
{
	pid_Son_t my_pid;
	ssize_t _fd_tops;
	my_pid.file = "Process.tmp";

	my_pid.text = "Process son ----> \t\t\t\t";

	if (cmd == NULL)
	{
		perror("Error");
		return (-1);
	}
	if (!my_pid.file)
		return (-1);
	my_pid.pid = fork();
	if (my_pid.pid == 0)
	{
		my_pid.pid = getpid();
		if (my_pid.pid != 0)
		{
			_fd_tops = open(my_pid.file, O_CREAT | O_RDWR, 0664);
			if (_fd_tops < 0)
				return (99);
			my_pid.text_pid = _itoa(my_pid.pid);
			if (my_pid.text_pid != NULL)
			{
				append_new_process(my_pid.file, my_pid.text_pid, my_pid.text);
			}
		}
		else
		{
			return (-1);
		}
	}

	return (0);
}

int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

/** **********************************************************************
 * 
 *                      FUNCTION PARSED
 * 
 *  **********************************************************************                      
*/

char **_parsed(char **input)
{
	char **tokens;
	char *token;
	int i = 0;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * BUFFSIZE);
	if (!tokens)
	{
		perror("ERROR");
		return (NULL);
	}
	token = strtok(*input, DELIMITS);
	for (; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIMITS);
	}
	tokens[i] = NULL;

	return (tokens);
}

/** **********************************************************************
 * 
 *                      FUNCTION STRINGS
 * 
 *  **********************************************************************                      
*/

char *_itoa(int n)
{
	register int r, k;
	int flag = 0;

	next = 0;
	if (n <= 0)
	{
		qbuf[next++] = '-';
		n = -n;
	}
	if (n == 0)
	{
		qbuf[next++] = '0';
	}
	else
	{
		k = 10000;
		while (k > 0)
		{
			r = n / k;
			if (flag || r > 0)
			{
				qbuf[next++] = '0' + r;
				flag = 1;
			}
			n -= r * k;
			k = k / 10;
		}
	}
	qbuf[next] = '\n';
	return (qbuf);
}

int len(char *str)
{
	return (lenR(str, 0));
}

/**
 * lenR - Functions copy values
 * @str: Destine of de buffer.
 * @counter: addres of the string search.
 * Return: If size == 0 or the function fails - NULL.
 *         Otherwise - a pointer to the array.
 */

int lenR(char *str, int counter)
{

	if (!(*str))
	{
		return (counter);
	}
	else
	{
		return (lenR(str + 1, counter + 1));
	}
}

/** **********************************************************************
 * 
 *                      FUNCTION CONSTRUCTOR
 * 
 *  **********************************************************************                      
*/

int check_builder(char **command)
{
	const_t run[] = {
		{"cd", NULL},
		{NULL, NULL}};

	int _check = 0;
	if (*command == NULL)
		return (-1);
	while ((run + _check)->command)
	{
		if (strcmp(command[0], (run + _check)->command) == 0)
			return (0);
		_check++;
	}
	return (-1);
}

int builder_handling(char **command, int status_er)
{
	unsigned int j;

	const_t cmds[] = {
		{"cd", get_process},
		{NULL, NULL}};

	j = 0;

	while ((cmds + j)->command)
	{
		if (strcmp(command[0], (cmds + j)->command) == 0)
			return ((cmds + j)->func(command, status_er));
		j++;
	}
	return (-1);
}

/** **********************************************************************
 * 
 *                      FUNCTION PRINCIPAL MAIN
 * 
 *  **********************************************************************                      

int main(__attribute__((unused)) int arg, char **argv)
{
	char **command, *line;
	int counter = 0, Execute_Loop = 1, status = 0;
	size_t linesize = 0;

	if (argv[0] == NULL)
		dprintf(STDERR_FILENO, "Usage: sh command inconrrect\n"), exit(97);

	signal(SIGINT, signal_line);

	while (Execute_Loop)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompter();
		getline(&line, &linesize, stdin);
		command = _parsed(argv);
		if (strcmp(command[0], "exit") == 0)
		{
			printf("Salir Del SIstema");
		}
		else if (check_builder(command))
		{
			status = builder_handling(command, status);
			continue;
		}
		else
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(" ===> Error:");
			}
		}
		printf("%s", line);
	}
	return (Execute_Loop);
}
*/

int main(void)
{
	char *command[] = {"/bin/ls", "-l", "/usr/", NULL};

	pid_t pid;

	if (command == NULL)
		return (-1);
	get_process();
	pid = pids_Son(*command);
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		_PRINT("No es 0\n");
	}

	return (0);
}