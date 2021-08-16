comp :
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format -g *.c

comp-1 :
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format -g main.c _printf.c _putchar.c get_format.c holberton.h print_basic.c print_advanced.c special_cases.c print_pro.c 

comp-holb :
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

comp-holb- : 
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

chown : 
	sudo chown dkbarb10 *

clean :
	rm -f programa *.o *.gch *.out

run : 
	./a.out