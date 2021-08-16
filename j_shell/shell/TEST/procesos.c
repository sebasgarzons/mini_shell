#include "shell.h"

int main(void)
{

    pid_Father_t my_ppid;
    pid_Son_t my_pid;
    ssize_t _fd_tops;

    my_ppid.file = "Process.tmp";
    my_pid.file = "Process.tmp";

    my_ppid.text = "Process Father ----> \t\t\t\t";
    my_pid.text = "Process son ----> \t\t\t\t";

    if (!my_ppid.file || !my_pid.file)
        return (-1);

    my_ppid.num_pid = getppid();
    if (my_ppid.num_pid != 0)
    {
        _fd_tops = open(my_ppid.file, O_CREAT | O_RDWR, 0664);
        if (_fd_tops < 0)
            return (99);

        my_ppid.text_pid = _itoa(my_ppid.num_pid);
        if (my_ppid.text_pid != NULL)
        {
            append_new_process(my_ppid.file, my_ppid.text_pid, my_ppid.text);
        }
    }

    my_pid.num_pid = getpid();
    if (my_pid.num_pid != 0)
    {
        my_pid.text_pid = _itoa(my_pid.num_pid);
        if (my_pid.text_pid != NULL)
        {
            append_new_process(my_pid.file, my_pid.text_pid, my_pid.text);
        }
    }

    close(_fd_tops);

    return (0);
}