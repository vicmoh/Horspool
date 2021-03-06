/***********************************
 * Vicky Mohammad
 * mohammav@uoguelph.ca
 ***********************************/

#include "header.h"

Instance* initInstance(){
    Instance* new = malloc(sizeof(Instance));
    new->data4 = NULL;
    new->data5 = NULL;
    new->data4Size = 6000;
    new->data5Size = 1;
    new->data4v2 = NULL;
    new->numberOfSearchFound = 0;
    new->numberOfPatternSwitch = 0;
    return new;
}//end constructor

void deleteInstance(Instance* vars){
    free2DArray(vars->data4, vars->data4Size);
    //free(vars->data5);
    free(vars);
}//end constructor

void free2DArray(char** toBeFreed, int size){
    for(int x=0; x<size; x++){
        free(toBeFreed[size]);
    }//end fpr
    free(toBeFreed);
}//end func

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
    printf("------------------------------------------\n");
}//end func

void loadData4(Instance* vars){
    //dec vars
    FILE* filePointer = fopen("./assets/data_4.txt", "r");
    int size = 6000*5;
    char** array = malloc(sizeof(array)*size);
    CustomArray* arrayForSorted = malloc(sizeof(CustomArray)*size);
    printf("Loading data 4...\n");
    for(int x=0; x<size; x++){
        char tempString[256];
        char sortedTempString[256];
        //for original
        fscanf(filePointer, "%s", tempString);
        array[x] = setString(tempString);
        //for sorted
        strcpy(sortedTempString, tempString);
        arrayForSorted[x].original = setString(tempString);
        qsort(sortedTempString, strlen(sortedTempString), sizeof(char), compareChar);
        arrayForSorted[x].sorted = setString(sortedTempString);
    }//end for
    printf("Data 4 loaded...\n");
    //return
    vars->data4 = array;
    vars->data4Size = size;
    vars->data4v2 = arrayForSorted;
    //debug
    for(int x=0; x<size; x++){
        //debug("debug D4: (%s)\n", vars->data4[x]);
    }//end for
    fclose(filePointer);
}//end func

void loadData5(Instance* vars){
    FILE* filePointer = fopen("./assets/data_5.txt", "r");
    int size = 0;
    char* data = calloc(2, sizeof(char)); data[0] = '\0';
    char charBuffer;
    printf("Loading data 5...\n");
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
    printf("Data 5 loaded...\n");
    //return
    vars->data5 = data;
    vars->data5Size = size;
    fclose(filePointer);
}//end func
