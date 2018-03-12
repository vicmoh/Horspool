/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

Helper* initHelper(){
    Helper new = malloc(sizeof(Helper));
    new->length = 0;
    new->numberRight = 0;
    new->count = 0;
    new->suffixIndex = 0;
    return new;
}//end constructor

GoodShift* initGoodShift(){
    GoodShift new = malloc(sizeof(goodShift));
    new->size = 0;
    new->stringIndex = 0;
    new->index = 0;
    new->count = 0;
    return new;
}//end constructor

Boyer* initBoyer(){
    Boyer new = malloc(sizeof(Boyer));
    new->found = 0;
    new->count = 0;
    new->patternShift = 0;
    new->numberRight = 0;
    new->flag = 0;
    new->stringSize = 0;
    return new;
}//end constructor

void readSuffix(char* string, char* suffix, int* stringIndex, int* numberRight, int* x, Helper* vars){
    //read through all the letters in the suffix
    while(*stringIndex < *x+1) {
        if(*stringIndex > -1){
            if(string[*stringIndex] == suffix[vars->suffixIndex]){
                length = length + 1;
                numberRight + numberRight + 1;
            }else{
                length = length + 1;
            }//end if
        }//end if
        *stringIndex = *stringIndex + 1;
        vars->suffixIndex = vars->suffixIndex + 1;
    }//end while
}//end func

void goodShiftTable(int suffixTable[], char* string){
    GoodShift gs = initGoodShift();
    gs->size = strlen(string);
    char suffix[gs->size];
    int suffixIndex = 0;

    //Initialize elements in table to max
    for(int x = gs->size-1; x>=0; x--){
        suffixTable[x] = gs->size;
    }//end for

    for(int x = gs->size-1; x>=0; x--){
        //Current index
        gs->index=0;
        gs->stringIndex = x, suffixIndex = x; 
        //Building suffix
        while(gs->stringIndex <= gs->size-1){
            suffix[gs->index] = string[gs->stringIndex];
            gs->index++;
            gs->stringIndex++;
        }//end while
    
        Helper* vars = initHelper();
        int count = 0;
        //Starting at first char not in the suffix
        for(int x = gs->size-gs->index-1; x>=0; x--){
            vars = initHelper();
            //Moving back the size of the suffix
            gs->stringIndex = x-gs->index-1;
            readSuffix(string, suffix, &gs->stringIndex, &numberRight, &x, vars);
            
            count = count + 1;
            //numright is equal to suffix length
            if(vars->numberRight == length) {
                suffixTable[suffixIndex] = count+gs->index-numberRight;
                break;
            }//end if
        }//end for
    }//end for
}//end func

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
    Boyer* boyer = initBoyer();
    boyer->stringSize = strlen(searchString)-1;
    
    for(int x =0; x<data5Size; x++){
        int n = strlen(line[i]);

        if(strlen(searchString) <= strlen(line[i])){
            int j = 0;
            while(j<n-m){
                patternShift++;
                count = 0;
                flag = 0;
                numRight = 0;
                int k;
                for(k =m-1; k>=0; k--){
                    if(line[i][j+k] == searchString[k]){
                        if(flag != 1){
                            numRight++;
                        }//end if
                        count++;
                    }else{
                        flag = 1;
                    }//end if
                }
                k = m - 1 - numRight;
                if(count == m){
                    found++;
                }
                int index = (unsigned char)line[i][j+k] - 32;
                int badValue, goodValue;
                goodValue = gST[m-numRight];
                if(bST[index]-numRight > 0){
                    badValue = bST[index]-numRight;
                else{
                    badValue = 1;
                }
                if(badValue>=goodValue){
                    j = j + badValue;
                }else{
                    j = j + goodValue;
                }
            }
        }
    }//end while
    time_t end = clock();

    //print the outcome
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of pattern switches: %d\n", (int)(vars->data5Size - strlen(searchString)) );
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func