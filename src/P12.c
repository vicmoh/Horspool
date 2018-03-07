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
    //debug("debug: bubsort = (%s)\n", tempArray);
    return tempArray;
}//end func

int compareChar(const void* first, const void* second){
    char* firstChar = (char*)first;
    char* secondChar = (char*)second;
    char result = *firstChar - *secondChar; 
    return result;
}//end func

int compareString(const void* first, const void* second){
    char* firstString = (char*)first;
    char* secondString = (char*)second;
    return strcmp(firstString, secondString);
}//end func

int binarySearch(char** array, int left, int right, char* beingSearched){
    bool stop = false;
    int numberFound = 0;
    qsort(array, 30000, sizeof(char*), compareString);
    while (left <= right){
        int middle = left + (right-left)/2;
        debug("debug: sorted = (%s)\n", array[middle]);
        if (strcmp(array[middle], beingSearched) == 0){
            stop = true;
            numberFound++;
        }else if(stop == true){
            return numberFound;
        }
        if (strcmp(array[middle], beingSearched) == -1){
            left = middle + 1;
        }else{
            right = middle - 1;
        }//end if
    }//end while
    return -1;
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
    char* sortedAnagram = calloc(256, sizeof(char));
    strcpy(sortedAnagram, anagram);
    qsort(sortedAnagram, strlen(sortedAnagram), sizeof(char), compareString);
    
    debug("debug: anagram = (%s)\n", anagram);

    //search for anagram through the array of data
    clock_t start = clock();
    //for(int x=0; x<vars->data4Size; x++){
        int found = binarySearch(vars->data4, 0, vars->data4Size-1, sortedAnagram);

        //int currentDataStringSize = strlen(vars->data4[x]);

        //dec vars for checking if its anagram
        //int numberOfCharFound = 0;
        //bool stringIsTheSame = false;
        //char* tempDataString = calloc(256, sizeof(char));
        //char* tempAnagram = calloc(256, sizeof(char));
        //strcpy(tempDataString, vars->data4[x]);
        //strcpy(tempAnagram, anagram);

        //sort the chars with bubble sort
        //char* tempSortedDataString = bubbleSort(tempDataString);
        //qsort(tempAnagram, strlen(tempAnagram), sizeof(char), compareString);
        //qsort(tempDataString, strlen(tempDataString), sizeof(char), compareString);

        //search if anagram found
        // if(strcmp(tempDataString, sortedAnagram) == 0){
        //     stringIsTheSame = true;
        // }//end if

        // //print and count and anagram founds
        // //debug("debug: numCharFound = %d, anagramSize = %d, tempData = %s\n", numberOfCharFound, anagramSize, tempDataString);
        // if(stringIsTheSame == true){
        //     //debug("debug: numCharFound = %d, anagramSize = %d, tempData = %s\n", numberOfCharFound, anagramSize, tempDataString);
        //     numberOfAnagramFound = numberOfAnagramFound + 1;
        //     //printf("%d: %s\n", numberOfAnagramFound, vars->data4[x]);
        // }//end if
        // stringIsTheSame = false;

        //free(tempSortedDataString);
        //free(tempAnagram);
        //free(tempDataString);
    //}
    clock_t end = clock();
    printf("Number of anagram found is %d\n", found);
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);

    free(anagram);
}//end func