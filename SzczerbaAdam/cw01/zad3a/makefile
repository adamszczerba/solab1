CC=gcc
CFLAGS=
AR=ar

all: static shared dynamic

.PHONY: all static-lib shared-lib static clean shared dynamic test

static-lib: libblockarray.a

shared-lib: libblockarray.so

libblockarray.a: blockarray-static.o
	$(AR) rcs libblockarray.a blockarray-static.o

blockarray-static.o: blockarray.c
	$(CC) $(CFLAGS) -c -o blockarray-static.o blockarray.c

blockarray-pic.o: blockarray.c
	$(CC) $(CFLAGS) -c -fPIC -o blockarray-pic.o blockarray.c

libblockarray.so: blockarray-pic.o
	$(CC) $(CFLAGS) -shared -fPIC -o libblockarray.so blockarray-pic.o

static: main-static

shared: main-shared

dynamic: main-dyn

main-static: main-static.o libblockarray.a
	$(CC) $(CFLAGS) -o main-static main-static.o -L. -l:libblockarray.a

main-static.o: main.c
	$(CC) $(CFLAGS) -c -o main-static.o main.c

main-shared: main-shared.o libblockarray.so
	$(CC) $(CFLAGS) -o main-shared main-shared.o -L. -lblockarray

main-shared.o: main.c
	$(CC) $(CFLAGS) -c -o main-shared.o main.c

main-dyn: main-dyn.o
	$(CC) $(CFLAGS) -o main-dyn main-dyn.o -ldl

main-dyn.o: main.c
	$(CC) $(CFLAGS) -c -DDYNAMIC -o main-dyn.o main.c

clean:
	rm *.o || true
	rm *.a || true
	rm *.so || true

test:

	echo "BIBLIOTEKA STATYCZNA" >> results3a.txt
	./main-static	75 5000 static 		| tee -a results3a.txt
	./main-static	75 5000 static search_element 1000 		| tee -a results3a.txt
	./main-static	75 5000 static remove 50 25 add 50 25 		| tee -a results3a.txt
	./main-static	75 5000 static remove_and_add 20 20 		| tee -a results3a.txt

	./main-static	75 5000 dynamic 		| tee -a results3a.txt
	./main-static	75 5000 dynamic search_element 1000 		| tee -a results3a.txt
	./main-static	75 5000 dynamic remove 50 25 add 50 25 		| tee -a results3a.txt
	./main-static	75 5000 dynamic remove_and_add 20 20 		| tee -a results3a.txt

	echo "BIBLIOTEKA DZIELONA" >> results3a.txt
	./main-shared	75 5000 static 		| tee -a results3a.txt
	./main-shared	75 5000 static search_element 1000 		| tee -a results3a.txt
	./main-shared	75 5000 static remove 50 25 add 50 25		 | tee -a results3a.txt
	./main-shared	75 5000 static remove_and_add 20 20 		| tee -a results3a.txt

	./main-shared	75 5000 dynamic 		| tee -a results3a.txt
	./main-shared	75 5000 dynamic search_element 1000 		| tee -a results3a.txt
	./main-shared	75 5000 dynamic remove 50 25 add 50 25 		| tee -a results3a.txt
	./main-shared	75 5000 dynamic remove_and_add 20 20 		| tee -a results3a.txt
	
	echo "BIBLIOTEKA LADOWANA DYNAMICZNIE" >> results3a.txt
	./main-dyn	75 5000 static 		| tee -a results3a.txt
	./main-dyn	75 5000 static search_element 1000 		| tee -a results3a.txt
	./main-dyn	75 5000 static remove 50 25 add 50 25 		| tee -a results3a.txt
	./main-dyn	75 5000 static remove_and_add 20 20 		| tee -a results3a.txt

	./main-dyn	75 5000 dynamic			| tee -a results3a.txt
	./main-dyn	75 5000 dynamic search_element 1000			| tee -a results3a.txt
	./main-dyn	75 5000 dynamic remove 50 25 add 50 25 			| tee -a results3a.txt
	./main-dyn	75 5000 dynamic remove_and_add 20 20			| tee -a results3a.txt
	
	
	
	


