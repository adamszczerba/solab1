#ifndef SZCZERBAADAM_CW01_ARRLIBRARY_H
#define SZCZERBAADAM_CW01_ARRLIBRARY_H

#endif //SZCZERBAADAM_CW01_ARRLIBRARY_H

typedef struct BlockArrayStruct{

    int blocksAmount;   //ilosc blokow
    int blockSize;    //tablica wielkosci blokow
    char **blocks;  //wskasnik na tabice wskaznikow do blokow zawierajace zmienne typu char

} BlockArray;

BlockArray *makeArray (int amountOfBlocks, int size, int isStatic);
//tworzenie nowej tablicy

void deleteArray (BlockArray *blckArray); //usuwanie tablicy

void addBlock (BlockArray *blckArray, int indxOfBlck,
               char* blck);    //dodawnie bloku, na ktory wspazuje przekazany indeks tablicy


void deleteBlock (BlockArray *blckArray, int indxOfBlck);  //usuowa blok, na ktory wskazuje przekazany indeks tablicy

char* findBlock (BlockArray *blckArray, int num); // zwraca wskaznik na blok o sumie kodow ASCII najblizszej wartosci num
