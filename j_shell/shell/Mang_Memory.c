#include "shell.h"
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */

void free_env(char **env)
{
    int i;

    for (i = 0; env[i]; i++)
    {
        free(env[i]);
    }
}