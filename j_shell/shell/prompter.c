#include "shell.h"

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