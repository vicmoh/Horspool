/***********************************
 * Vicky Mohammad
 * 0895381
 * referenced: http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
 * referenced: https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/
 ***********************************/
 
#include "header.h"

Boyer* newBoyer(){
    Boyer* new = malloc(sizeof(Boyer));
    new->suffixIndex=0;
    new->shiftingIndex=0;
    new->shiftPatern = 0;
    new->patternLength = 0;
    new->dataLength = 0;
    new->numberOfSearchFound = 0;
    new->numberOfPatternSwitch = 0;
    new->borderPosition = NULL;
    new->shift = NULL;
    return new;
}//end constructor

void setTables(Boyer* vars, char* data, char* patern){
    debug("calling setTables\n");
    int patternLength = strlen(patern);
    int dataLength = strlen(data);
    vars->patternLength = patternLength;
    vars->dataLength = dataLength;
    vars->borderPosition = malloc(sizeof(int)*patternLength+1);
    vars->shift = malloc(sizeof(int)*patternLength+1);
    debug("return setTables\n");
}//end setter

void setIndexToZero(Boyer* vars){
    vars->suffixIndex = 0;
    vars->shiftingIndex = 0;
}//end setter

void setIndexForGoodSuffix(Boyer* vars){
    vars->suffixIndex = vars->patternLength;
    vars->shiftingIndex = vars->patternLength+1;
}//end setter

void preprocessGoodSuff(char *searchString, Boyer* boyer){
    int i=boyer->patternLength, j=boyer->patternLength+1;
    boyer->borderPosition[i]=j;
    while(i>0){
        while(j<=boyer->patternLength && searchString[i-1] != searchString[j-1]){
            if (boyer->shift[j]==0){
                boyer->shift[j] = j-i;
            }//end if
            j = boyer->borderPosition[j];
        }//end while
        i = i - 1;
        j = j - 1;
        boyer->borderPosition[i] = j;
    }//end while
}//end func

void preprocessBadChar(Boyer* boyer){
    int i, j;
    j = boyer->borderPosition[0];
    for(i=0; i<=boyer->patternLength; i++){
        if(boyer->shift[i]==0){
            boyer->shift[i] = j;
        }//end if
        if (i==j){
            j = boyer->borderPosition[j];
        }//end if
    }//end for
}//end func
 
Boyer* search(char *data, char *stringToBeSearched){
    //dec vars
    Boyer* boyer = newBoyer();
    setTables(boyer, data, stringToBeSearched);
    //create shift table
    //int borderPosition[boyer->patternLength+1], shift[boyer->patternLength+1];
 
    for(int i=0;i<boyer->patternLength+1;i++){
        boyer->shift[i]=0;
    }//end for
 
    preprocessGoodSuff(stringToBeSearched, boyer);
    preprocessBadChar(boyer);
 
    while(boyer->shiftPatern <= boyer->dataLength-boyer->patternLength){
        boyer->numberOfPatternSwitch++;
        int j = boyer->patternLength-1;
        while(j >= 0 && stringToBeSearched[j] == data[boyer->shiftPatern+j]){
            j = j - 1;
            //boyer->numberOfPatternSwitch++;
        }//end while
        if (j<0){
            boyer->shiftPatern = boyer->shiftPatern + boyer->shift[0];
            boyer->numberOfSearchFound++;
        }else{
            boyer->shiftPatern = boyer->shiftPatern + boyer->shift[j+1];
            //boyer->numberOfPatternSwitch++;
        }//end if
    }//end while
    return boyer;
}//end func

void boyerMoore(Instance* vars){
    char* searchString = calloc(256, sizeof(char));
    //ask for the anagram
    printf("Enter the string to search: "); 
    searchString = input(searchString);
    printf("Calculating...\n"); 

    time_t start = clock();
    Boyer* boyer = search(vars->data5, searchString);
    time_t end = clock();

    int numberOfSearchFound = boyer->numberOfSearchFound;
    int numberOfPatternSwitch = boyer->numberOfPatternSwitch-1;
    
    //print the outcome
    printf("----------<<<((( FEEDBACK )))>>>----------\n");
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of pattern switches: %d\n", numberOfPatternSwitch);
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
    printf("----------------------------------------\n");
}//end if