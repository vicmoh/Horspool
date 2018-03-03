/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

Instance* initInstance(){
    Instance* new = malloc(sizeof(Instance));
    new->data4 = NULL;
    new->data5 = NULL;
    new->data4Size = 6000;
    new->data5Size = 1;
    return new;
}//end constructor

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

void loadData4(Instance* vars){
    //dec vars
    FILE* filePointer = fopen("./assets/data_4.txt", "r");
    int size = 6000*5;
    int* array = malloc(sizeof(int)*size);
    debug("Loading data 4...\n");
    for(int x=0; x<size; x++){
        fscanf(filePointer, "%d", &array[x]);
    }//end for
    debug("Data 4 loaded...\n");
    //return
    vars->data4 = array;
    vars->data4Size = size;
    fclose(filePointer);
}//end func

void loadData5(Instance* vars){
    FILE* filePointer = fopen("./assets/data_5.txt", "r");
    int size = 0;
    char* data = calloc(2, sizeof(char)); data[0] = '\0';
    char charBuffer;
    debug("Loading data 5...\n");
    while(filePointer != NULL){
        charBuffer = getc(filePointer);
        if(charBuffer == EOF){
            break;
        }//end if
        data[size] = charBuffer;
        size++;
        data = realloc(data, sizeof(char)*(size+1));
        data[size] = '\0';
    }//end while
    debug("Data 5 loaded...\n");
    //return
    vars->data5 = data;
    vars->data5Size = size;
    fclose(filePointer);
}//end func