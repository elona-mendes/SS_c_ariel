CC=gcc
FLAGS= -g -Wall 

all: stringProg

stringProg: main.o textFunc.o
	$(CC) $(FLAGS) -o stringProg main.o textFunc.o 

textFunc.o: textFunc.c textFunc.h
	$(CC) $(FLAGS) -c textFunc.c

main.o: main.c textFunc.h
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o stringProg