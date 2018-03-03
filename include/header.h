/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#ifndef HEADER_H
#define HEADER_H 

typedef struct{
    int menu;
}Instance;

//libs and macros
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define debug if(true)printf
//helper functions
char* setString(char* string);
char* input(char* string);
void output(char* string);

#endif
