#include "shell.h"

/**
 * main - function principal
*/

/*
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

/**
 * check_builder - function que ayuda a saber cuando mi comando es cd, ls dir, etc.
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

/**
 * builder_handling- function que ayuda a hacer un mejor manejo de los errores.
*/

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
