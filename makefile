mycomp: mycomp.o complex.o
	gcc -Wall mycomp.o complex.o -o mycomp -lm

mycomp.o: mycomp.c complex.h
	gcc -c -ansi -Wall mycomp.c -o mycomp.o

complex.o: complex.c complex.h
	gcc -c -ansi -Wall complex.c -o complex.o

