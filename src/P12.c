/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

char* bubbleSort(char* array){
    //dec vars
    char temp;
    int tempArraySize = strlen(array);
    char* tempArray = calloc(tempArraySize, sizeof(char));
    strcpy(tempArray, array);
    //sort the
    for (int x = 0; x < tempArraySize; x++) {
        for (int y = 0; y < tempArraySize-1-x; y++) {
            if (tempArray[y] > tempArray[y+1]) {
                temp = tempArray[y];
                tempArray[y] = tempArray[y+1];
                tempArray[y+1] = temp;
            }//end if
        }//end for
    }//end for
    debug("debug: bubsort = (%s)\n", tempArray);
    return tempArray;
}//end func

void presortAnagram(Instance* vars){
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

        //sort the chars with bubble sort
        char* tempSortedDataString = bubbleSort(tempDataString);

        //search if anagram found
        for(int y=0; y<anagramSize; y++){
            for(int z=0; z<currentDataStringSize; z++){
                //set the temp string char with another, to prevent duplicate count
                if(tempAnagram[y] == tempSortedDataString[z]){
                    numberOfCharFound++;
                    tempSortedDataString[z] = 'X';
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

        free(tempSortedDataString);
        free(tempAnagram);
        free(tempDataString);
    }//end for

    free(anagram);
}//end func