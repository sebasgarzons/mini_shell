#include "shell.h"

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