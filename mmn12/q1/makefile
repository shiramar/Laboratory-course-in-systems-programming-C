mymagic : magic.o matrix.o print.o
	gcc -g -ansi -Wall -pedantic magic.o matrix.o print.o -o mymagic
magic.o : magic.c data.h
	gcc -c -ansi -Wall magic.c -o magic.o
matrix.o: matrix.c data.h
	gcc -c -ansi -Wall matrix.c -o matrix.o
print.o: print.c data.h
	gcc -c -ansi -Wall print.c -o print.o
