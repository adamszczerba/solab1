CC=gcc

all: staticLib	sharedLib test

static:
	$(CC) -Wall -c blockarray.c -fsanitize=address -g -O0
	ar rcs blockarray.a blockarray.o

shared:
	$(CC) -Wall -c -fPIC blockarray.c
	$(CC) -Wall -shared -fPIC -o blockarray.so blockarray.o



staticVersion:
	make static
	$(CC) -Wall -c main.c -fsanitize=address -g -O0
	$(CC) -Wall -o main main.c blockarray.a -I. -lasan
	make test2

sharedVersion:
	make shared
	$(CC) -Wall -c main.c
	$(CC) -Wall -o main main.c -L. blockarray.so -I.
	make test

test2:
	./main 75 5000 dynamic search_element 1000

test:
	./main	75 5000 static
	./main	75 5000 static search_element 1000
	./main	75 5000 static remove 50 25 add 50 25
	./main	75 5000 static remove_and_add 20 20

	./main	5000 500 dynamic
	./main	5000 500 dynamic search_element 1000
	./main	50000 5000 dynamic remove 50 100 add 50 100
	./main	100000	1000 dynamic remove_and_add 500 500


clean:
	rm -f *.o

