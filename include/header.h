/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#ifndef HEADER_H
#define HEADER_H 

typedef struct{
    char** data4;
    char* data5;
    int data4Size;
    int data5Size;
}Instance;

//libs and macros
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
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
//question 1.1
void bruteforceAnagram(Instance* vars);


#endif
