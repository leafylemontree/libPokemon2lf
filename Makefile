all:
	gcc -c utils.c 
	gcc -c gen3.c
	gcc -c main.c
	gcc -o main utils.o gen3.o main.o -lm
	./main
