/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

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
    if (low > high){
        printf("Anagram not found\n");
        return -1;
    }//end if
    int middle = (low + high) / 2;
    if(strcmp(array[middle].sorted, beingSearched) == 0){
        debug("debug: search %s = %s\n", array[middle].sorted, beingSearched);
        return middle;
    }else if (strcmp(array[middle].sorted, beingSearched) > 0){
        return binarySearch(array, low, middle - 1, beingSearched);
    }else if (strcmp(array[middle].sorted, beingSearched) < 0){
        return binarySearch(array, middle + 1, high, beingSearched);
    }//end if
    return -1;
}//end func

void presortAnagram(Instance* vars){
    //dec vars
    char* anagram = calloc(256, sizeof(char));
    int numberOfAnagramFound = 0;

    //ask for the anagram
    printf("Enter the string to find anagram: "); 
    anagram = input(anagram); 
    //int anagramSize = strlen(anagram);
    char* sortedAnagram = calloc(256, sizeof(char));
    strcpy(sortedAnagram, anagram);
    qsort(sortedAnagram, strlen(sortedAnagram), sizeof(char), compareChar);
    
    debug("debug: sorted anagram = (%s)\n", sortedAnagram);
    printf("Calculating...\n"); 

    //pre sort the data in the array
    clock_t start = clock();
    qsort(vars->data4v2, vars->data4Size, sizeof(CustomArray), compareCustomArray);

    //debug
    // for(int x=0; x<vars->data4Size; x++){
    //     debug("debug: testing if sorted %s\n", vars->data4v2[x].sorted);
    // }

    //search the anagram binary searh found
    int indexOftheAnagramFound = binarySearch(vars->data4v2, 0, vars->data4Size-1, sortedAnagram);
    clock_t end = clock();
    
    //print the anagram found
    if(indexOftheAnagramFound > -1){
        numberOfAnagramFound++;
        int iter = indexOftheAnagramFound;
        printf("%d: %s\n", numberOfAnagramFound, vars->data4v2[iter].original);
        while(true){
            iter++;
            if(strcmp(sortedAnagram, vars->data4v2[iter].sorted) != 0){
                break;
            }//end if
            numberOfAnagramFound++;
            printf("%d: %s\n", numberOfAnagramFound, vars->data4v2[iter].original);
        }//end while
        iter = indexOftheAnagramFound;
        while(true){
            iter--;
            if(strcmp(sortedAnagram, vars->data4v2[iter].sorted) != 0){
                break;
            }//end if
            numberOfAnagramFound++;
            printf("%d: %s\n", numberOfAnagramFound, vars->data4v2[iter].original);
        }//end while
    }//end while

    printf("----------<<<((( FEEDBACK )))>>>----------\n");
    printf("Number of anagram found is %d\n", numberOfAnagramFound);
    printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
    printf("----------------------------------------\n");
}//end func