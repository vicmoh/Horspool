// /***********************************
//  * Vicky Mohammad
//  * 0895381
//  * referenced: http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
//  ***********************************/

// #include "header.h"

// int max(int num1, int num2){
//     int result = 0;
//     if(num1 > num2){
//         result = num1;
//     }else{
//         result = num2;
//     }//end if
//     return result;
// }//end func

// void goodSuffix(char* searchString, char* data, int dataSize, int badCharacter[], Instance* vars){
//     int index = 0;
//     int offSet = 0;
//     int numberOfPatternSwitch = 0;
//     int numberOfSearchFound = 0;
//     int searchSize = strlen(searchString);
//     //loop through the data
//     while (index <= (dataSize-searchSize)) {
//         offSet = searchSize - 1;

//         while (offSet > -1 && searchString[offSet] == data[index+offSet]){
//             int newIndex = vars->data5[index + searchSize - 1];
//             if(newIndex < 0){
//                 index = index + 1;
//             }//end if
//             offSet = offSet - 1;
//             numberOfPatternSwitch = numberOfPatternSwitch + 1;
//         }//end while

//         if (offSet <= -1) {
//             numberOfSearchFound = numberOfSearchFound + 1;
//             int result = 0;
//             if(index + searchSize < dataSize){
//                 int dataIndex = data[index+searchSize];
//                 result = searchSize-badCharacter[dataIndex];
//                 numberOfPatternSwitch = numberOfPatternSwitch + 1;
//             }else{
//                 result = 1;
//             }///end if
//             index = index + result;
//         }else{
//             int dataIndex = data[index+searchSize];
//             int maxValue = max(1, offSet - badCharacter[dataIndex]);
//             index = index + maxValue;
//             numberOfPatternSwitch = numberOfPatternSwitch + 1;
//         }//end if
//     }//end while
//     vars->numberOfSearchFound = numberOfSearchFound;
//     vars->numberOfPatternSwitch = numberOfPatternSwitch;
// }//end

// void badCharacterHeuristic(char* search, int* badCharacter, int size){
//     for(int x=0; x<size; x++){
//         badCharacter[x] = -1;
//     }//end for
//     for(int x=0; x<strlen(search); x++){
//         int index = search[x];
//         badCharacter[index] = x;
//     }//end for
// }//end func

// void boyerMoore(Instance* vars){
//     //dec vars
//     const int badCharSize = 1000;
//     int badCharacter[badCharSize];//1000 just in case
//     char* searchString = calloc(256, sizeof(char));
//     int numberOfSearchFound = 0;
//     int numberOfPatternSwitch = 0;

//     //ask for the word search
//     printf("Enter the string to find anagram: "); 
//     searchString = input(searchString);
//     time_t start = clock();
 
//     //pre-processing
//     badCharacterHeuristic(searchString, badCharacter, badCharSize);

//     //searching the word 
//     int data5Size = strlen(vars->data5);
//     goodSuffix(searchString, vars->data5, data5Size, badCharacter, vars);
//     numberOfSearchFound = vars->numberOfSearchFound;
//     numberOfPatternSwitch = vars->numberOfPatternSwitch;
//     time_t end = clock();

//     //print the outcome
//     printf("Total number search found: %d\n", numberOfSearchFound);
//     printf("Number of pattern switches: %d\n", numberOfPatternSwitch);
//     printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
// }//end func