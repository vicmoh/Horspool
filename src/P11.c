/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

void bruteforceAnagram(Instance* vars){
    //dec vars
    char* anagram = calloc(256, sizeof(char));
    int numberOfAnagramFound;

    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    anagram = input(anagram); 
    printf("\n");
    int anagramSize = strlen(anagram);
    bool foundAnagram = false;

    //search for anagram through the array of data
    for(int x=0; x<vars->data4Size; x++){
        int currentDataStringSize = strlen(vars->data4[x]);

        //search if anagram found
        for(int y=0; y<currentDataStringSize; y++){
            foundAnagram = false;
            for(int z=0; z<anagramSize; z++){
                if(anagram[y] == anagram[z]){
                    foundAnagram = true;
                }//end if
            }//end for
            if(foundAnagram == false){
                break;
            }//end if
        }//end for

        //print and count and anagram founds
        if(foundAnagram == true){
            numberOfAnagramFound = numberOfAnagramFound + 1;
            printf("%d: %s\n", numberOfAnagramFound, vars->data4[x]);
        }//end if
    }//end for
}//end func
