#include "blockarray.h"
#include <stdlib.h>
#include <string.h>

BlockArray* makeArray (int amountOfBlocks, int size){
    BlockArray* toRet = NULL;
    toRet = (BlockArray *)calloc(1, sizeof(BlockArray));

    toRet->blocks = (char **)calloc(amountOfBlocks, sizeof(char*));
    toRet->blocksAmount = amountOfBlocks;
    toRet->blockSize=size;

    return toRet;

}

void deleteArray (BlockArray *blckArray){
    if (blckArray == NULL) return;


    for(int i = 0; i<blckArray->blocksAmount; i++){
        free(blckArray->blocks[i]);
    }

    free(blckArray);
}

void addBlock (BlockArray *blckArray,int indxOfBlck,
               char* blck){
    blckArray->blocks[indxOfBlck] = (char*)calloc(blckArray->blockSize, sizeof(char));

    memcpy(blckArray->blocks[indxOfBlck], blck, blckArray->blockSize);

}

void deleteBlock (BlockArray *blckArray, int indxOfBlck){
    free(blckArray->blocks[indxOfBlck]);
    blckArray->blocks[indxOfBlck]=NULL;
}

unsigned int blockSum (char* block, int blockSize){
    int toRet = 0;
    for(int i = 0; i<blockSize; i++){
        toRet +=(int)((unsigned char)block[i]);
    }
    return toRet;

}

char* findBlock (BlockArray *blckArray, int num){
    int bestVal = blockSum(blckArray->blocks[0], blckArray->blockSize);
    char* toRet = blckArray->blocks[0];

    for(int i = 1; i < blckArray->blocksAmount; i++){
        int tmpVal = blockSum(blckArray->blocks[i], blckArray->blockSize);

        if(abs(tmpVal-num) < abs(bestVal-num)){
            bestVal = tmpVal;
            toRet = blckArray->blocks[i];
        }
    }

    return toRet;

}


