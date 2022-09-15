lab3: lab.o cipher.o
	gcc -std=c99 -o lab3 cipher.o lab3.o

cipher.o: cipher.c
	gcc -std=c99 -c cipher.c

lab.o: lab3.c cipher.h
	gcc -std=c99 -c lab3.c

