#include "shell.h"

/* Integer to ASCII for signed decimal integers. */

static int next;
static char qbuf[8];

/**
 * _itoa - convert one nomber in to string
 * return:string
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
