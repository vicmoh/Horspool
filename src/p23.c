/***********************************
 * Vicky Mohammad
 * 0895381
 * referenced: http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
 * referenced: https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/
 ***********************************/
 
#include "header.h"
 
void preprocessGoodSuff(int* shift, int* borderPosition, char* patern, int paternLength){
    int i=paternLength, j=paternLength+1;
    borderPosition[i]=j;
 
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
 
//bad char
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
 
/*Search for a pattern in given text using
  Boyer Moore algorithm with Good suffix rule */
void search(char* search, char* patern){
    int shiftPaternBetweenSearchString=0, j;
    int paternLength = strlen(patern);
    int searchLength = strlen(search);
 
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