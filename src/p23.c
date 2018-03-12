/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

void suffixes(char* string, int* suffix){
    int stringSize = strlen(string);
    int indexShift = 0, 

    suffix[stringSize-1] = stringSize;
    int mostRightPattern = stringSize-1;
    for(int x = stringSize-2; x >= 0; x--){
        if (x > mostRightPattern && suffix[x + stringSize-indexShift-1] < x - mostRightPattern){
            suffix[x] = suffix[x + stringSize-indexShift-1];
        }else{
            if (x < mostRightPattern){
                mostRightPattern = x;
                indexShift = x;
            }//end if
            while(mostRightPattern >= 0 && string[mostRightPattern] == string[mostRightPattern + stringSize-indexShift-1]){
                //--mostRightPattern;
                mostRightPattern = mostRightPattern - 1;
                suffix[x] = indexShift - mostRightPattern;
            }//end while
        }//end else
    }//end for
}//end func
 
void goodSuffixShift(char* string, int goodSuffix[]) {
    int stringSize = strlen(string);
    int suffix[stringSize] = 0;

    for(int x = 0; x < stringSize; x++)
        goodSuffix[x] = stringSize;
    }//end for

    suffixes(string, suffix);

    for(int x = stringSize-1; x >= 0; x--){
        if(suffix[x] == x+1){
            for(int y=0 ; y < stringSize-1-x; y++){
                if(goodSuffix[y] == stringSize){
                    goodSuffix[y] = stringSize-x-1;
                }//end if
            }//end for
        }//end if
    }//end for

    for(int x = 0; x <= stringSize-2; x++){
        goodSuffix[stringSize-suffix[x]-1] = stringSize-x-1;
    }//end fpr
}//end for

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
    const int goodSuffSize = 1000;
    int badCharacter[badCharSize];//1000 just in case
    int goodSuffix[goodSuffSize];
    char* searchString = calloc(256, sizeof(char));
    int numberOfSearchFound = 0;

    //ask for the word search
    printf("Enter the string to find anagram: "); 
    searchString = input(searchString);
    time_t start = clock();
 
    //pre-processing
    int searchStringSize = strlen(searchString);
    goodSuffixShift(searchString, searchStringSize, goodSuffix);
    badCharacterHeuristic(searchString, badCharacter, badCharSize);

    //searching the word 
    int index = 0;
    int data5Size = strlen(vars->data5);
    while(index <= data5Size-searchStringSize) {
        for(int x = searchStringSize-1; x>=0 && searchString[x] == vars->data5[x+index]; x--){
            if(x < 0) {
                //when search is found
                index = index + goodSuffix[0];
            }else{
                index = index + max(goodSuffix[x], badCharacter[vars->data5[x+index]]-searchStringSize+x+1);
            }//end if
        }//end for
    }//end while
    time_t end = clock();

    //print the outcome
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of pattern switches: %d\n", (int)(vars->data5Size - strlen(searchString)) );
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func