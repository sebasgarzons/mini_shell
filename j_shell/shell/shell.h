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
