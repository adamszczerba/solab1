#polecenia kompilujace pliki zrodlowe biblioteki
#tworzace biblioteke w 2 wersjach: statyczna i dzielona

CC=gcc
#nazwa kompialtora



all: static shared

static:
	$(CC) -Wall -c blockarray.c    #kompilacja
	ar crs libblockarray.a blockarray.o    #linkowanie i tworzenie archiwum

shared:
	$(CC) -Wall -fPIC -c blockarray.c #fpic position independent code
	$(CC) -shared -o libblockarray.so blockarray.o

clean:
	rm -f *.o



#cel(nazwa pliku docelowego):skladniki
#    komenda (tworzenie celu z skadnikow)