/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

void badCharacterHeuristic(char* search, int* badCharacter, int size){
    for(int x=0; x<size; x++){
        badCharacter[x] = -1;
    }//end for
    for(int x=0; x<strlen(search); x++){
        int index = search[x];
        badCharacter[index] = x;
    }//end for
}//end func

int max(int num1, int num2){
    int result = 0;
    if(num1 > num2){
        result = num1;
    }else{
        result = num2;
    }//end if
    return result;
}//end func

void boyerMoore(Instance* vars){
    //dec vars
    const int badCharSize = 1000;
    int badCharacter[badCharSize];//1000 just in case
    char* searchString = calloc(256, sizeof(char));
    int numberOfSearchFound = 0;

    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    searchString = input(searchString);
    time_t start = clock();
    badCharacterHeuristic(searchString, badCharacter, badCharSize);
    // while(index <= ){

    // }//end while
    time_t end = clock();

    //print the outcome
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of pattern switches: %d\n", (int)(vars->data5Size - strlen(searchString)) );
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func