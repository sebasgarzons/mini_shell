/**## LIBRARIES*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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

/** STRUCTS
typedef struct constructor
{
    char **command;
    int(func)(char **line, int er);
} const_t;*/

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
int pids_fathers(pid_Father_t my_ppid)
{
    ssize_t _fd_tops;

    my_ppid.file = "Process.tmp";
    my_ppid.text = "Process Father ----> \t\t\t\t";

    if (!my_ppid.file)
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
    close(_fd_tops);

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

/**
 * PROTOTIPO DE MAIN PARA CHECKEAR PROCESOS
 * 
int main()
{
    char *cmd = "ls";
    pid_t pid;
    if (cmd == NULL)
        return (-1);
    pid = pids_Son(cmd);
    if (pid == -1)
    {
        perror("Error");
        return (-1);
    }
    if (pid == 0)
    {
        _PRINT("No es 0");
    }

    return (0);
}

**/