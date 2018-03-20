//
// Created by adam on 17.03.18.
//

#include "blockarray.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/resource.h>


//done
char* genRandomBlock(int blockSize){
    char* charsCollection = "abcdeABCDE12345";
    int charsCollectionLength = strlen(charsCollection);

    char* toRet = (char*) calloc(blockSize, sizeof(char));
    for(int i = 0; i < blockSize-1; i++){
        toRet[i]=charsCollection[rand()%charsCollectionLength];
    }
    toRet[blockSize - 1] = '\0';

    return  toRet;
}


//done, to check
void fillByRandomChars( BlockArray *thisBlckArr ){
    for(int i = 0; i < thisBlckArr->blocksAmount; i++){
        addBlock(thisBlckArr, i, genRandomBlock(thisBlckArr->blockSize));
    }
}

//done, to check
BlockArray* createTable( int size, int blockSize, int isStatic ){
    BlockArray* toRet = makeArray( size, blockSize, isStatic );
    fillByRandomChars( toRet );

    return toRet;
}

//char* findElement(int num){} done, findBlock fuction, same sygnature

// done, toCheck
void removeNumOfBlock( BlockArray *thisBlckArr, int numberOfBlocks, int startIndex){
    for(int i = startIndex; i < numberOfBlocks
                            && (startIndex + i) < thisBlckArr->blockSize-1; i++){
        deleteBlock(thisBlckArr, i);
    }
}

// done, toCheck
void addNumOfBlock( BlockArray *thisBlckArr, int numberOfBlocks, int startIndex){
    for(int i = startIndex; i < numberOfBlocks
                            && (startIndex + i) < thisBlckArr->blockSize-1; i++){
        addBlock(thisBlckArr, i, genRandomBlock(thisBlckArr->blockSize));
    }
}

// done, toCheck
void removeAndAddNumOfBlock( BlockArray *thisBlckArr, int numberOfBlock, int startIndex){
    removeNumOfBlock(thisBlckArr, numberOfBlock, startIndex);
    addNumOfBlock(thisBlckArr, numberOfBlock, startIndex);
}


void execOption ( BlockArray* thisBlckArr, int* optionIndex, char* argv[]){

    if(strcmp(argv[*optionIndex], "search_element")){   //1 param
        (*optionIndex)++; //kolejnym argumentem jest wartosc do jakiej mamy sie zblizyc

        findBlock(thisBlckArr, atoi(argv[*optionIndex]));
    }

    else if(strcmp(argv[*optionIndex], "remove")){  //2 param: startIndex i amount
        (*optionIndex)++;
        int startIndx = atoi(argv[*optionIndex]);

        (*optionIndex)++;
        int amountOfBlcks = atoi(argv[*optionIndex]);

        removeNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }

    else if(strcmp(argv[*optionIndex], "add")){ // 1 param: startIndex i amount
        (*optionIndex)++;
        int startIndx = atoi(argv[*optionIndex]);

        (*optionIndex)++;
        int amountOfBlcks = atoi(argv[*optionIndex]);

        addNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }

    else if(strcmp(argv[*optionIndex], "remove_and_add")){  // 1 param: start index i amount
        (*optionIndex)++;
        int startIndx =atoi(argv[*optionIndex]);

        (*optionIndex)++;
        int amountOfBlcks = atoi(argv[*optionIndex]);

        removeAndAddNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }

    (*optionIndex)++;
}

//zwraca czas w sekundach, najpierw czas poczatkowy
long calcTimeFrom2TimevalVal( struct timeval t0, struct timeval t1){

    long toRet = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;

    return toRet/1000000.0;
}

/*
arg1 -> liczba el tablicy
arg2 -> rozmiar bloku
arg3 -> sposob alokacji
arg4 -> spis wykonywanych operacji
 */
int main (int argc, char* argv[]){

    srand(time(NULL));

    int elementAmount = atoi(argv[1]);
    int blocksSize = atoi(argv[2]);
    char* alocateKind = argv[3];

    int isStatic;
    if( !(strcmp(alocateKind, "static"))    ){
        isStatic = 1;
    }else if(   !(strcmp(alocateKind, "dynamic"))   ){
        isStatic = 0;
    }

    struct rusage tt0, tt1;
    struct timeval t0, t1;

    getrusage(RUSAGE_SELF, &tt0);
    gettimeofday(&t0, NULL);


    BlockArray *thisBlckArr = makeArray(elementAmount, blocksSize, isStatic);

    int i = 4;
    while(argv[i] != NULL){
        execOption(thisBlckArr, &i, argv);
    }

    getrusage(RUSAGE_SELF, &tt1);
    gettimeofday(&t1, NULL);



    long realTime = calcTimeFrom2TimevalVal(t0, t1);
    long userTime = calcTimeFrom2TimevalVal(tt0.ru_utime, tt1.ru_utime);
    long systemTime = calcTimeFrom2TimevalVal(tt0.ru_stime, tt1.ru_stime);

    // sposoby zalaczania bibliotek

    if(!(strcmp(alocateKind, "static"))){
        printf("tablica alokowana statycznie\n");
    }else if(!(strcmp(alocateKind, "dynamic"))){
        printf("tablica alokowana dynamicznie\n");
    }

    printf("real time: %ld s, user time: %ld s, system time: %ld s\n",
           realTime, userTime, systemTime);


    return 1;
}