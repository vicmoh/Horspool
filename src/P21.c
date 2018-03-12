/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

bool compareTwoString(const char* string1, const char* string2, int index){
    //for loop till the size of the array till it finds it
    int counter = 0;
    for(int x=0; x<strlen(string1); x++){
        if(string1[x] == string2[x+index]){
            counter++;
        }//end if
    }//end for
    if(counter == strlen(string1)){
        return true;
    }//end if
    return false;
}//end func

void bruteForceStringSearch(Instance* vars){
    char* searchString = calloc(256, sizeof(char));
    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    searchString = input(searchString);

    //keep shifting the char array till it finds the two string
    time_t start = clock();
    int numberSearchFound = 0;
    for(int x=0; x<vars->data5Size-strlen(searchString); x++){
        bool found = compareTwoString(searchString, vars->data5, x);
        if(found == true){
            numberSearchFound++;
        }//end if
    }//end for
    time_t end = clock();

    //ratio = patterShift / runningTime

    //print the outcome
    printf("Total number search found: %d\n", numberSearchFound);
    printf("Number of pattern switches: %d\n", (int)(vars->data5Size - strlen(searchString)) );
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func