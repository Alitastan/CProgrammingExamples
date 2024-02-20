
remind: remind.o readline.o
	gcc -o remind remind.o readline.o

readline.o: readline.c readline.h
	gcc -c readline.c

remind.o: remind.c readline.h
	gcc -c remind.c