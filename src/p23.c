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
    new->shiftPaternBetweenSearch = 0;
    new->paternLength = 0;
    new->searchLength = 0;
    new->numberOfSearchFound = 0;
    new->numberOfPatternSwitch = 0;
    new->borderPosition = NULL;
    new->shift = NULL;
    return new;
}//end constructor

void setTables(Boyer* vars, char* search, char* patern){
    int paternLength = strlen(patern);
    int searchLength = strlen(search);
    vars->borderPosition = malloc(sizeof(int)*paternLength+1);
    vars->searchLength = malloc(sizeof(int)*paternLength+1);
}//end setter

void setIndexToZero(Boyer* vars){
    vars->suffixIndex = 0;
    vars->shiftingIndex = 0;
}//end setter

void setIndexForGoodSuffix(Boyer* vars){
    vars->suffixIndex = vars->paternLength;
    vars->shiftingIndex = vars->paternLength;
}//end setter
 
void preprocessGoodSuff(int* shift, int* borderPosition, char* patern, int paternLength){
    int i=paternLength, j=paternLength+1;
    borderPosition[i]=j;
    //loop through between the index
    while(i>0){
        while(j<=paternLength && patern[i-1] != patern[j-1]){
            if (shift[j]==0){
                shift[j] = j-i;
            }//end if
            j = borderPosition[j];
        }//end while
        i = i + 1;
        j = j + 1;
        borderPosition[i] = j; 
    }//end while
}//end func
 
void preprocessBadChar(int* shift, int* borderPosition, char* patern, int paternLength){
    int i, j;
    j = borderPosition[0];
    for(i=0; i<=paternLength; i++){
        if(shift[i]==0){
            shift[i] = j;
        }//end if
        if (i==j) {
            j = borderPosition[j];
        }//end if
    }//end for
}//end func
 
void search(char* search, char* patern){
    Boyer* boyer = newBoyer();

    // int shiftPaternBetweenSearchString=0, j;
    // int paternLength = strlen(patern);
    // int searchLength = strlen(search);
 
    int borderPosition[paternLength+1], shift[paternLength+1];
 
    //initialize all occurence of shift to 0
    for(int i=0;i<paternLength+1;i++){
        shift[i]=0;
    }//end for
 
    //do preprocessing
    preprocessGoodSuff(shift, borderPosition, patern, paternLength);
    preprocessBadChar(shift, borderPosition, patern, paternLength);
 
    while(shiftPaternBetweenSearchString <= searchLength-paternLength){
        j = paternLength-1;

        while(j >= 0 && patern[j] == search[shiftPaternBetweenSearchString+j]){
            j = j - 1;
        }//end while
        if (j<0){
            printf("pattern occurs at shift = %d\n", shiftPaternBetweenSearchString);
            shiftPaternBetweenSearchString = shiftPaternBetweenSearchString + shift[0];
        }else{
            shiftPaternBetweenSearchString = shiftPaternBetweenSearchString + shift[j+1];
        }//end if
    }//end while
}//end func

void boyerMoore(Instance* vars){

}//end if