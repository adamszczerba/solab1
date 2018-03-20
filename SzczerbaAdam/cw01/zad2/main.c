//
// Created by adam on 17.03.18.
//

#include "blockarray.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>


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
BlockArray* createTable( int size, int blockSize ){
    BlockArray* toRet = makeArray( size, blockSize );
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

        findBlock(thisBlckArr, (int)strtol(argv[*optionIndex], NULL, 10));
    }
    else if(strcmp(argv[*optionIndex], "remove")){  //2 param: startIndex i amount
        (*optionIndex)++;
        int startIndx = (int) strtol(argv[*optionIndex], NULL, 10);

        (*optionIndex)++;
        int amountOfBlcks = (int) strtol(argv[*optionIndex], NULL, 10);

        removeNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }
    else if(strcmp(argv[*optionIndex], "add")){ // 1 param: startIndex i amount
        (*optionIndex)++;
        int startIndx = (int) strtol(argv[*optionIndex], NULL, 10);

        (*optionIndex)++;
        int amountOfBlcks = (int) strtol(argv[*optionIndex], NULL, 10);

        addNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }
    else if(strcmp(argv[*optionIndex], "remove_and_add")){  // 1 param: start index i amount
        (*optionIndex)++;
        int startIndx = (int) strtol(argv[*optionIndex], NULL, 10);

        (*optionIndex)++;
        int amountOfBlcks = (int) strtol(argv[*optionIndex], NULL, 10);

        removeAndAddNumOfBlock(thisBlckArr, amountOfBlcks, startIndx);
    }
}

/*
arg1 -> liczba el tablicy
arg2 -> rozmiar bloku
arg3 -> sposob alokacji
arg4 -> spis wykonywanych operacji
 */
int main (int argc, char* argv[]){

    srand(time(NULL));

    int elementAmount = (int) strtol(argv[1], NULL, 10);
    int blocksSize = (int) strtol(argv[2], NULL, 10);
    char* alocateKind = argv[3];

    BlockArray* thisBlckArr = makeArray(elementAmount, blocksSize); //uwzglednij  argv[3]


    int isStatic;
    if(!(strcmp(argv[3], "static"))){ //funkcja zwraca 0 tj "falsz" gdy takie same
        isStatic = 1;
    }else if(!(strcmp(argv[3], "dynamic"))){
        isStatic = 0;
    }


    // obsluga polecen
    int i = 4;
    while(argv[i] != NULL){
        execOption(thisBlckArr, &i, argv);
    }

    return 1;
}