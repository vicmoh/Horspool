/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

#include "header.h"

int main(int argc, char** argv){
    //dec vars
    char* menu = calloc(256, sizeof(char));
    Instance* vars = initInstance();

    //load datas
    loadData4(vars);
    //loadData5(vars);
    
    //menu
    while(true){
        //ask the user
        printf("1) Brute force anagrams\n");
        printf("2) Presort anagrams\n");
        printf("3) Brute force string search\n");
        printf("4) Horspool Algorithm\n");
        printf("5) Exit\n");
        printf("Enter menu: "); 
        menu = input(menu); 
        printf("\n");

        //menu condition
        if(strcmp(menu, "1") == 0){
            bruteforceAnagram(vars);
        }else if(strcmp(menu, "2") == 0){

        }else if(strcmp(menu, "3") == 0){

        }else if(strcmp(menu, "4") == 0){

        }else if(strcmp(menu, "5") == 0){
            output("Exiting program...\n");
            exit(0);
        }else{
            output("Invalid input, please re-enter\n");
        }//end if
    }//end while
    
    deleteInstance(vars);
    free(menu);
    return 0;
}//end main
