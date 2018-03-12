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
    new->paternLength = 0;
    new->dataLength = 0;
    new->numberOfSearchFound = 0;
    new->numberOfPatternSwitch = 0;
    new->borderPosition = NULL;
    new->shift = NULL;
    return new;
}//end constructor

void setTables(Boyer* vars, char* data, char* patern){
    int paternLength = strlen(patern);
    int dataLength = strlen(data);
    vars->paternLength = paternLength;
    vars->dataLength = dataLength;
    vars->borderPosition = malloc(sizeof(int)*paternLength+1);
    vars->shift = malloc(sizeof(int)*paternLength+1);
}//end setter

void setIndexToZero(Boyer* vars){
    vars->suffixIndex = 0;
    vars->shiftingIndex = 0;
}//end setter

void setIndexForGoodSuffix(Boyer* vars){
    vars->suffixIndex = vars->paternLength;
    vars->shiftingIndex = vars->paternLength+1;
}//end setter
 
void preprocessGoodSuff(Boyer* boyer, char* patern){
    setIndexForGoodSuffix(boyer);
    boyer->borderPosition[boyer->suffixIndex]=boyer->shiftingIndex;
    //loop through between the index
    while(boyer->suffixIndex>0){
        while(boyer->shiftingIndex<=boyer->paternLength && patern[boyer->suffixIndex-1] != patern[boyer->shiftingIndex-1]){
            if (boyer->shift[boyer->shiftingIndex]==0){
                boyer->shift[boyer->shiftingIndex] = boyer->shiftingIndex-boyer->suffixIndex;
            }//end if
            boyer->shiftingIndex = boyer->borderPosition[boyer->shiftingIndex];
        }//end while
        boyer->suffixIndex = boyer->suffixIndex + 1;
        boyer->shiftingIndex = boyer->shiftingIndex + 1;
        boyer->borderPosition[boyer->suffixIndex] = boyer->shiftingIndex; 
    }//end while
}//end func
 
void preprocessBadChar(Boyer* boyer, char* patern){
    setIndexToZero(boyer);
    boyer->shiftingIndex = boyer->borderPosition[0];
    for(boyer->suffixIndex=0; boyer->suffixIndex<=boyer->paternLength; boyer->suffixIndex++){
        if(boyer->shift[boyer->suffixIndex]==0){
            boyer->shift[boyer->suffixIndex] = boyer->shiftingIndex;
        }//end if
        if (boyer->suffixIndex==boyer->shiftingIndex) {
            boyer->shiftingIndex = boyer->borderPosition[boyer->shiftingIndex];
        }//end if
    }//end for
}//end func
 
Boyer* search(char* data, char* patern){
    Boyer* boyer = newBoyer();
    setTables(boyer, data, patern);
 
    //initialize all occurence of shift to 0
    for(boyer->suffixIndex=0;boyer->suffixIndex<boyer->paternLength+1;boyer->suffixIndex++){
        boyer->shift[boyer->suffixIndex]=0;
    }//end for
 
    //do preprocessing
    preprocessGoodSuff(boyer, patern);
    preprocessBadChar(boyer, patern);
 
    while(boyer->shiftPatern <= boyer->dataLength - boyer->paternLength){
        boyer->shiftingIndex = boyer->paternLength-1;

        while(boyer->shiftingIndex >= 0 && patern[boyer->shiftingIndex] == data[boyer->shiftPatern+boyer->shiftingIndex]){
            boyer->shiftingIndex = boyer->shiftingIndex - 1;
        }//end while
        if (boyer->shiftingIndex<0){
            printf("pattern occurs at shift = %d\n", boyer->shiftPatern);
            boyer->numberOfSearchFound++;
            boyer->shiftPatern = boyer->shiftPatern + boyer->shift[0];
        }else{
            boyer->numberOfPatternSwitch++;
            boyer->shiftPatern = boyer->shiftPatern + boyer->shift[boyer->shiftingIndex+1];
        }//end if
    }//end while
    return boyer;
}//end func

void boyerMoore(Instance* vars){
    char* searchString = calloc(256, sizeof(char));
    //ask for the anagram
    printf("Enter the string to search: "); 
    searchString = input(searchString);

    time_t start = clock();
    Boyer* boyer = search(vars->data5, searchString);
    time_t end = clock();

    int numberOfSearchFound = boyer->numberOfSearchFound;
    int numberOfPatternSwitch = boyer->numberOfPatternSwitch;
    
    //print the outcome
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of pattern switches: %d\n", numberOfPatternSwitch);
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end if