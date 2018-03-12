/***********************************
 * Vicky Mohammad
 * 0895381
 * referenced: http://www-igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
 * referenced: https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/
 ***********************************/
 
#include "header.h"

// Boyer* newBoyer(){
//     Boyer* new = malloc(sizeof(Boyer));
//     new->suffixIndex=0;
//     new->shiftingIndex=0;
//     new->shiftPatern = 0;
//     new->paternLength = 0;
//     new->dataLength = 0;
//     new->numberOfSearchFound = 0;
//     new->numberOfPatternSwitch = 0;
//     new->borderPosition = NULL;
//     new->shift = NULL;
//     return new;
// }//end constructor

// void setTables(Boyer* vars, char* data, char* patern){
//     debug("calling setTables\n");
//     int paternLength = strlen(patern);
//     int dataLength = strlen(data);
//     vars->paternLength = paternLength;
//     vars->dataLength = dataLength;
//     vars->borderPosition = malloc(sizeof(int)*paternLength+1);
//     vars->shift = malloc(sizeof(int)*paternLength+1);
//     debug("return setTables\n");
// }//end setter

// void setIndexToZero(Boyer* vars){
//     vars->suffixIndex = 0;
//     vars->shiftingIndex = 0;
// }//end setter

// void setIndexForGoodSuffix(Boyer* vars){
//     vars->suffixIndex = vars->paternLength;
//     vars->shiftingIndex = vars->paternLength+1;
// }//end setter
 
// void preprocessGoodSuff(Boyer* boyer, char* patern, int* shift, int* borderPosition){
//     debug("calling preprocessGoodSuff\n");
//     setIndexForGoodSuffix(boyer);
//     borderPosition[boyer->suffixIndex]=boyer->shiftingIndex;
//     //loop through between the index
//     while(boyer->suffixIndex>0){
//         while(boyer->shiftingIndex<=boyer->paternLength && patern[boyer->suffixIndex-1] != patern[boyer->shiftingIndex-1]){
//             if (shift[boyer->shiftingIndex]==0){
//                 shift[boyer->shiftingIndex] = boyer->shiftingIndex-boyer->suffixIndex;
//             }//end if
//             boyer->shiftingIndex = borderPosition[boyer->shiftingIndex];
//         }//end while
//         boyer->suffixIndex = boyer->suffixIndex + 1;
//         boyer->shiftingIndex = boyer->shiftingIndex + 1;
//         borderPosition[boyer->suffixIndex] = boyer->shiftingIndex; 
//     }//end while
//     debug("return preprocessGoodSuff\n");
// }//end func
 
// void preprocessBadChar(Boyer* boyer, char* patern, int* shift, int* borderPosition){
//     debug("calling preprocessBadChar\n");
//     setIndexToZero(boyer);
//     boyer->shiftingIndex = borderPosition[0];
//     for(boyer->suffixIndex=0; boyer->suffixIndex<=boyer->paternLength; boyer->suffixIndex++){
//         if(shift[boyer->suffixIndex]==0){
//             shift[boyer->suffixIndex] = boyer->shiftingIndex;
//         }//end if
//         if (boyer->suffixIndex==boyer->shiftingIndex) {
//             boyer->shiftingIndex = borderPosition[boyer->shiftingIndex];
//         }//end if
//     }//end for
//     debug("return preprocessBadChar\n");
// }//end func
 
// Boyer* search(char* data, char* patern){
//     debug("calling search\n");
//     Boyer* boyer = newBoyer();
//     setTables(boyer, data, patern);
//     int borderPosition[boyer->paternLength+1], shift[boyer->paternLength+1];
 
//     //initialize all occurence of shift to 0
//     for(boyer->suffixIndex=0;boyer->suffixIndex<boyer->paternLength+1;boyer->suffixIndex++){
//         boyer->shift[boyer->suffixIndex] = 0;
//     }//end for
 
//     //do preprocessing
//     preprocessGoodSuff(boyer, patern, shift, borderPosition);
//     preprocessBadChar(boyer, patern, shift, borderPosition);
//     setIndexToZero(boyer);
 
//     while(boyer->shiftPatern <= boyer->dataLength - boyer->paternLength){
//         boyer->shiftingIndex = boyer->paternLength - 1;

//         while(boyer->shiftingIndex >= 0 && patern[boyer->shiftingIndex] == data[boyer->shiftPatern+boyer->shiftingIndex]){
//             boyer->shiftingIndex = boyer->shiftingIndex - 1;
//         }//end while
//         if (boyer->shiftingIndex<0){
//             printf("pattern occurs at shift = %d\n", boyer->shiftPatern);
//             boyer->numberOfSearchFound++;
//             boyer->shiftPatern = boyer->shiftPatern + boyer->shift[0];
//         }else{
//             boyer->numberOfPatternSwitch++;
//             boyer->shiftPatern = boyer->shiftPatern + boyer->shift[boyer->shiftingIndex+1];
//         }//end if
//     }//end while
//     debug("return search\n");
//     return boyer;
// }//end func

// int numberOfSearchFound = 0;
// int numberOfPatternSwitch = 0;

// // preprocessing for strong good suffix rule
// void preprocess_strong_suffix(int *shift, int *bpos,
//                                 char *pat, int m)
// {
//     // m is the length of pattern 
//     int i=m, j=m+1;
//     bpos[i]=j;
 
//     while(i>0)
//     {
//         /*if character at position i-1 is not equivalent to
//           character at j-1, then continue searching to right
//           of the pattern for border */
//         while(j<=m && pat[i-1] != pat[j-1])
//         {
//             /* the character preceding the occurence of t in 
//                pattern P is different than mismatching character in P, 
//                we stop skipping the occurences and shift the pattern
//                from i to j */
//             if (shift[j]==0)
//                 shift[j] = j-i;
 
//             //Update the position of next border 
//             j = bpos[j];
//         }
//         /* p[i-1] matched with p[j-1], border is found.
//            store the  beginning position of border */
//         i--;j--;
//         bpos[i] = j; 
//     }
// }
 
// //Preprocessing for case 2
// void preprocess_case2(int *shift, int *bpos,
//                       char *pat, int m)
// {
//     int i, j;
//     j = bpos[0];
//     for(i=0; i<=m; i++)
//     {
//         /* set the border postion of first character of pattern
//            to all indices in array shift having shift[i] = 0 */
//         if(shift[i]==0)
//             shift[i] = j;
 
//         /* suffix become shorter than bpos[0], use the position of 
//            next widest border as value of j */
//         if (i==j)
//             j = bpos[j];
//     }
// }
 
// /*Search for a pattern in given text using
//   Boyer Moore algorithm with Good suffix rule */
// void search(char *text, char *pat)
// {
//     // s is shift of the pattern with respect to text
//     int s=0, j;
//     int m = strlen(pat);
//     int n = strlen(text);
 
//     int bpos[m+1], shift[m+1];
 
//     //initialize all occurence of shift to 0
//     for(int i=0;i<m+1;i++) shift[i]=0;
 
//     //do preprocessing
//     preprocess_strong_suffix(shift, bpos, pat, m);
//     preprocess_case2(shift, bpos, pat, m);
 
//     while(s <= n-m)
//     {
 
//         j = m-1;
 
//         /* Keep reducing index j of pattern while characters of
//              pattern and text are matching at this shift s*/
//         while(j >= 0 && pat[j] == text[s+j])
//             j--;
 
//         /* If the pattern is present at current shift, then index j
//              will become -1 after the above loop */
//         if (j<0)
//         {
//             printf("pattern occurs at shift = %d\n", s);
//             s += shift[0];
//         }
//         else
//             /*pat[i] != pat[s+j] so shift the pattern
//               shift[j+1] times  */
//             s += shift[j+1];
//     }
 
// }

// void boyerMoore(Instance* vars){
//     char* searchString = calloc(256, sizeof(char));
//     //ask for the anagram
//     printf("Enter the string to search: "); 
//     searchString = input(searchString);

//     time_t start = clock();
//     Boyer* boyer = search(vars->data5, searchString);
//     time_t end = clock();

//     int numberOfSearchFound = boyer->numberOfSearchFound;
//     int numberOfPatternSwitch = boyer->numberOfPatternSwitch;
    
//     //print the outcome
//     printf("Total number search found: %d\n", numberOfSearchFound);
//     printf("Number of pattern switches: %d\n", numberOfPatternSwitch);
//     printf("Execution time is %f seconds\n", (double)(end-start)/ (double)CLOCKS_PER_SEC);
// }//end if