CC=gcc

all: staticLib	sharedLib test

static:
	$(CC) -Wall -c -o blockarray.o blockarray.c -ggdb -Og
	ar rcs libblockarray.a blockarray.o

#shared:
#	$(CC) -Wall -c -fPIC blockarray.c
#	$(CC) -Wall -shared -fPIC -o blockarray.so blockarray.o



staticVersion:
	$(CC) -Wall -c -o main.o main.c -ggdb -Og
	$(CC) -Wall -o main main.o libblockarray.a

#sharedVersion:
#	make shared
#	$(CC) -Wall -c main.c -ggdb
#	$(CC) -Wall -o main main.c -L. blockarray.so -I.
#	make test


test:
	./main	75 5000 static | tee raport2.txt
	./main	75 5000 static search_element 1000 | tee -a raport2.txt
	./main	75 5000 static remove 50 25 add 50 25 | tee -a raport2.txt
	./main	75 5000 static remove_and_add 20 20 | tee -a raport2.txt


	#./main	75 5000 dynamic
	#./main	75 5000 dynamic search_element 1000
	#./main	75 5000 dynamic remove 50 25 add 50 25
	#./main	75 5000 dynamic remove_and_add 20 20


clean:
	rm -f *.o

