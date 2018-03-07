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
    int result = (int)(*firstChar) - (int)(*secondChar);
    return result;
}//end func

int compareCustomArray(const void* first, const void* second){
    CustomArray* firstString = (CustomArray*)(first);
    CustomArray* secondString = (CustomArray*)(second);
    //debug("debug: compare custom %s = %s\n", firstString->sorted, secondString->sorted);
    int result = strcmp(firstString->sorted, secondString->sorted);
    return result;
}//end func

int binarySearch(CustomArray* array, int low, int high, char* beingSearched){
    int middle;
    if (low > high){
        printf("Anagram not found\n");
        return;
    }//end if
    middle = (low + high) / 2;
    if(strcmp(array[middle].sorted, beingSearched) == 0){
        debug("debug: search %s = %s\n", array[middle].sorted, beingSearched);
        return middle;
    }else if (strcmp(array[middle].sorted, beingSearched) > 0){
        return binarySearch(array, low, middle - 1, beingSearched);
    }else{
        return binarySearch(array, middle + 1, high, beingSearched);
    }//end if
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
    qsort(sortedAnagram, strlen(sortedAnagram), sizeof(char), compareChar);
    
    debug("debug: sorted anagram = (%s)\n", sortedAnagram);

    //search for anagram through the array of data
    clock_t start = clock();

    qsort(vars->data4v2, vars->data4Size, sizeof(CustomArray), compareCustomArray);

    //debug
    // for(int x=0; x<vars->data4Size; x++){
    //     debug("debug: testing if sorted %s\n", vars->data4v2[x].sorted);
    // }

    numberOfAnagramFound = binarySearch(vars->data4v2, 0, vars->data4Size-1, sortedAnagram);

    clock_t end = clock();
    printf("Number of anagram found is %d\n", numberOfAnagramFound);
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
}//end func