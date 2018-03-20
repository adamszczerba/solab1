CC=gcc

all: staticLib	sharedLib test

static:
	$(CC) -Wall -c blockarray.c
	ar rcs blockarray.a blockarray.o

shared:
	$(CC) -Wall -c -fPIC blockarray.c
	$(CC) -Wall -shared -fPIC -o blockarray.so blockarray.o



staticVersion:
	make static
	$(CC) -Wall -c main.c
	$(CC) -Wall -o main main.c blockarray.a -I.
	make test

sharedVersion:
	make shared
	$(CC) -Wall -c main.c
	$(CC) -Wall -o main main.c -L. blockarray.so -I.
	make test


test:
	./main	5000 500 static
	./main	5000 500 static search_element 1000
	./main	50000 5000 static remove 50 100 add 50 100
	./main	100000	1000 static remove_and_add 500 500

	./main	5000 500 dynamic
	./main	5000 500 dynamic search_element 1000
	./main	50000 5000 dynamic remove 50 100 add 50 100
	./main	100000	1000 dynamic remove_and_add 500 500


clean:
	rm -f *.o

