#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

_printf("======================\n");
    _printf("****** d CASES ******\n");
    _printf("======================\n");
    printf("Printf   : %d\n", 1134001);
    _printf("_Printf:     %d\n", 1134001);

    printf("Printf   : %d\n", -4567);
    _printf("_Printf:     %d\n", -4567);

    printf("Printf   : %d\n", 0);
    _printf("_Printf:     %d\n", 0);

    printf("Printf   : %d\n", INT_MAX);
    _printf("_Printf:     %d\n", INT_MAX);

    printf("Printf   : %d\n", INT_MIN);
    _printf("_Printf:     %d\n", INT_MIN);

    printf("Printf   : %d\n", NULL);
    _printf("_Printf:     %d\n", NULL);

      /* ========================= */
    /* 			%i CASES		 */
    /* ========================= */
    printf("======================\n");
    printf("****** i CASES ******\n");
    printf("=====================\n");
    printf("Printf   : %i\n", 237482);
    _printf("_Printf:     %i\n", 237482);

    printf("Printf   : %i\n", -328472);
    _printf("_Printf:     %i\n", -328472);

    printf("Printf   : %i\n", 0);
    _printf("_Printf:     %i\n", 0);

    printf("Printf   : %i\n", INT_MAX);
    _printf("_Printf:     %i\n", INT_MAX);

    printf("Printf   : %i\n", INT_MIN);
    _printf("_Printf:     %i\n", INT_MIN);

    _printf("======================\n");
    _printf("****** EDGE CASES ******\n");
    _printf("======================\n");
    printf("Expected length:    %%%%");
    printf("Current length:     %%%%%%\n");
    printf("Expected length:    %d\n");
    printf("Current length:     %d\n");
    printf("Expected length:    %d\n");
    printf("Current length:     %d\n");
    printf("Expected output:    %d\n", INT_MAX);
    _printf("Current output:     %d\n", INT_MAX);
    printf("Expected output:    %d\n", INT_MIN);
    _printf("Current output:     %d\n", INT_MIN);
    printf("Expected output:    %d\n", NULL);
    _printf("Current output:     %d\n", NULL);
    _printf("print-- %s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 93", " Please wait", '\n');
    printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');


    _printf("======================\n");
    _printf("****** o CASES ******\n");
    _printf("======================\n");
    printf("Printf : %%%o%0%o\n", "Hackeado", "Tonto");
    _printf("_Printf : %%%o%0%o\n", "Hackeado", "Tonto");

    printf("printf:    %%%%\n", NULL);
    _printf("_Printf : %otest%%\n", NULL);

    printf("printf:    %%%%\n", NULL);
    _printf("_Printf : %otest%%\n", NULL);

    printf("printf:    %o\n", "Hola");
    _printf("_Printf : %o\n", "Hola");

    printf("printf:    %o\n", "Hola");
    _printf("_Printf : %o\n", "Hola");

    printf("printf:    %o\n", INT_MAX);
    _printf("_Printf : %o\n", INT_MAX);

    printf("printf:    %o\n", INT_MIN);
    _printf("_Printf : %o\n", INT_MIN);

    printf("printf:    %o\n", NULL);
    _printf("_Printf : %o\n", NULL);

    return (0);
}