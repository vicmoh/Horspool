/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#ifndef HEADER_H
#define HEADER_H 

typedef struct{
    char* original;
    char* sorted;
}CustomArray;

typedef struct{
    char** data4;
    char* data5;
    int data4Size;
    int data5Size;
    CustomArray* data4v2;
    int numberOfSearchFound;
    int numberOfPatternSwitch;
}Instance;

typedef struct{
    //prepocess good suffix vars
    int suffixIndex; int shiftingIndex;
    //preprocess bad character vars
    
    // search vars
    int shiftPaternBetweenSearch;
    int paternLength;
    int paternLength;
    //ouput vars
    int numberOfSearchFound;
    int numberOfPatternSwitch;
}Helper;

//libs and macros
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#define debug if(true)printf
//helper functions
Instance* initInstance();
void deleteInstance(Instance* vars);
void free2DArray(char** toBeFreed, int size);
char* setString(char* string);
char* input(char* string);
void output(char* string);
void loadData4(Instance* vars);
void loadData5(Instance* vars);
//1.1
void bruteforceAnagram(Instance* vars);
//1.2
int compareChar(const void* first, const void* second);
int binarySearch(CustomArray* array, int low, int high, char* beingSearched);
void presortAnagram(Instance* vars);
//2.1
bool compareTwoString(const char* string1, const char* string2, int index);
void bruteForceStringSearch(Instance* vars);
//2.2
void horspool(Instance* vars);
void horspoolShiftTable(char* search, int table[], int tableSize);
//2.3
void boyerMoore(Instance* vars);

#endif
