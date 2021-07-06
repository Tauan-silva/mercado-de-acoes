#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
    
    int option;
    title title1, title2, title3;

    initialize(title1, title2, title3);
    option = menu();

    switch (option){
        case 0:{
            exit(1);
            break;
        }
        case 1:{
            buy();
            break;
        }

        case 2:{
            sell();
            break;
        }
        default:{
            printf("Opcao invalida.");
            break;
        }
    }

    return 0;
}