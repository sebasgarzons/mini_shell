#include "shell.h"

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
