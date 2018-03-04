/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

void bruteforceAnagram(Instance* vars){
    //dec vars
    char* anagram = calloc(256, sizeof(char));
    int numberOfAnagramFound = 0;

    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    anagram = input(anagram); 
    printf("\n");
    int anagramSize = strlen(anagram);
    
    debug("debug: anagram = (%s)\n", anagram);

    //search for anagram through the array of data
    for(int x=0; x<vars->data4Size; x++){
        int currentDataStringSize = strlen(vars->data4[x]);

        //if string sizez does not much dont bother counting
        if(anagramSize != currentDataStringSize){
            continue;
        }//end if

        //dec vars for checking if its anagram
        int numberOfCharFound = 0;
        char* tempDataString = calloc(256, sizeof(char));
        char* tempAnagram = calloc(256, sizeof(char));
        strcpy(tempDataString, vars->data4[x]);
        strcpy(tempAnagram, anagram);

        //search if anagram found
        for(int y=0; y<anagramSize; y++){
            for(int z=0; z<currentDataStringSize; z++){
                //set the temp string char with another, to prevent duplicate count
                if(tempAnagram[y] == tempDataString[z]){
                    numberOfCharFound++;
                    tempDataString[z] = 'X';
                    tempAnagram[y] = 'x';
                }//end if
            }//end for
        }//end for

        //print and count and anagram founds
        //debug("debug: numCharFound = %d, anagramSize = %d, tempData = %s\n", numberOfCharFound, anagramSize, tempDataString);
        if(numberOfCharFound == anagramSize){
            debug("debug: numCharFound = %d, anagramSize = %d, tempData = %s\n", numberOfCharFound, anagramSize, tempDataString);
            numberOfAnagramFound = numberOfAnagramFound + 1;
            printf("%d: %s\n", numberOfAnagramFound, vars->data4[x]);
        }//end if

        free(tempAnagram);
        free(tempDataString);
    }//end for

    free(anagram);
}//end func
