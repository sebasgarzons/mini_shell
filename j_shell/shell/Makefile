shelling_ : 
	gcc -g  -Wall -Werror -Wextra -pedantic -std=gnu89 main.c _init_shel.c 

shelling : 
	gcc -g  -Wall -Werror -Wextra -pedantic -std=gnu89 main.c _printf.c -o _shelling

mains : 
	gcc -g  -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o a.out


No_error :
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format -Wno-error main.c -o a.out

comp-all :
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

comp-holb- : 
	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

chown : 
	sudo chown dkbarb10 *

clean :
	rm -f shelling_ *.o *.gch *.out

run : 
	./a.out
running :
	./a.out ls como

shellingR :
	./_shelling