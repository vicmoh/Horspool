/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

void horspoolShiftTable(char* search, int table[], int tableSize){
    int searchSize = strlen(search);
    for(int x=0; x<tableSize; x++){
        table[x] = searchSize;
    }//end for
    for(int x=0; x < searchSize - 1; x++){
        int index = search[x];
        table[index] = searchSize - 1 - x;
    }//end for
}//end func

void horspool(Instance* vars){
    //dec vars
    const int tableSize = 1000;
    int table[tableSize];//1000 just in case
    char* searchString = calloc(256, sizeof(char));
    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    searchString = input(searchString);
    //debug("debug: searchString = (%s)\n", searchString);
    
    //calculate and search
    int numberOfSearchFound = 0;
    int index = 0;
    time_t start = clock();
    horspoolShiftTable(searchString, table, tableSize);
    //debug("debug: data5Size = (%d)\n", vars->data4Size);
    int data5Size = strlen(vars->data5);
    int searchStringSize = strlen(searchString);
    //debug("debug: strlen(data5) == (%d)\n", data5Size);
    //debug("\n%s\n", vars->data5);
    while(index < data5Size - searchStringSize){
        int newIndex = vars->data5[index + searchStringSize - 1];
        if(newIndex < 0){
            index++;
            newIndex = vars->data5[index + searchStringSize - 1]; 
        }
        //debug("debug: searchString found = (%s)\n", searchString);
        if(searchString[searchStringSize - 1] == newIndex && memcmp(searchString, vars->data5 + index, searchStringSize - 1) == 0){
            numberOfSearchFound = numberOfSearchFound + 1;
            //debug("debug: searchString found = (%s)\n", searchString);
        }///end if
        index = index + table[newIndex];
    }//end fors
    time_t end = clock();

    //print the outcome
    printf("Total number search found: %d\n", numberOfSearchFound);
    printf("Number of switches: %d\n", (int)(vars->data5Size - strlen(searchString)) );
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func