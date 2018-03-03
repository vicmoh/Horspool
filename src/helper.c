/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

char* setString(char* string){
     char* newString = calloc(strlen(string)+9, sizeof(char)* strlen(string)+9 );
    strcpy(newString, string);
    return newString;
}//end func

char* input(char* string){
    fgets(string, 256, stdin);
    string[strcspn(string, "\r\n")] = '\0';
    return string;
}//end func

void output(char* string){
    printf("----------<<<((( FEEDBACK )))>>>----------\n");
    printf("%s", string);
    printf("----------------------------------------\n");
}//end func