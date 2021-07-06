#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

list *head = NULL;
list *chain = NULL;

list * createList(title value){
    list *p = (list*) malloc(sizeof(list));

    if(p == NULL){
        printf("\nFailed to allocate memory.\n");
        return NULL;
    }

    p->title = value;
    p->pLink = NULL;

    head = chain = p;

    return p;

}

list * addItemList(title value){
    if (head == NULL)
        return createList(value);
    
    list *p = (list*) malloc(sizeof(list));

    if(p == NULL){
        printf("\nFailed to allocate memory.\n");
        return NULL;
    }

    p->title = value;
    p->pLink = NULL;

    chain->pLink = p;
    chain = p;

    return p;
}

int isVoidList(){
	// se head for NULL, então a lista está vazia
	if(head == NULL)
		return 1;
	return 0;
}

list *fetchItemList(title value, list **previous){

    if(isVoidList())
        return NULL;

    list *p = head;
    list *aux_previous = NULL;

    int hasFound = 0;

    while(p != NULL){
        if(p->title.cod == value.cod && p->title.amount == value.amount){
            hasFound = 1;
            break;
        }

        aux_previous = p;
        p = p->pLink;
    }

    if(hasFound){
        if (previous)
        *previous = previous;
        return p;
    }

    return NULL;
}

int removeItemList(title value){
    list *previous = NULL;
    list *item = fetchItemList(value, &previous);

    if(item == NULL)
        return 0;
    
    if(previous != NULL)
        previous->pLink = item->pLink;
    
    if(item == head)
        head = item->pLink;
    
    free(item);
    item = NULL;

    return 1;
}

void printList(){
    list *aux = head;
    int position = 0;
    while(aux != NULL){
        printf("[%d] %s ", position, aux->title.cod);
        printf("%.2f ", aux->title.value);
        printf("%d\n", aux->title.amount);
        drawLine(".", 18);
        printf("\n");
        position++;
        aux = aux->pLink;
    }
}

title getValuesFromFile(char *fileName){
    FILE *openFile;
    title titleName;

    if((openFile = fopen(fileName, "r")) == NULL){
        printf("Error.");
        exit(1);
    }

    char name[6];
    int amount;
    float value;

    while(!feof(openFile))
        fscanf(openFile, "%s %f %d", name, &value, &amount);
    
    strcpy(titleName.cod, name);
    titleName.amount = amount;
    titleName.value = value;

    fclose(openFile);

    return titleName;
}   

void drawLine(char *caractere, int amount){
    for (int i = 0; i < amount; i++){
        printf("%s", caractere);
    }
    
}

void header(char *heading, char *caractere){
    drawLine(caractere, 51);
    printf("\n");
    drawLine(caractere, 10);
    printf("%s", heading);
    drawLine(caractere, 10);
    printf("\n");
    drawLine(caractere, 51);
    printf("\n\n");
}

void initialize(title title1, title title2, title title3){

    title1 = getValuesFromFile("PETR4.txt");
    title2 = getValuesFromFile("VALE5.txt");
    title3 = getValuesFromFile("ITSA4.txt");

    addItemList(title1);
    addItemList(title2);
    addItemList(title3);
    
}

void buy(title t1, title t2, title t3){
    int option;
    cleanScreen();
    header(" Simulador de mercado de acoes ", ".");
    printList();
    printf("\nDigite o numero referente a acao desejada: ");
    scanf("%d", &option);

    switch (option){
        case 0:{
            int amount;
            float value;

            cleanScreen();
            header(t1.cod, ".");
            printf("\nValor: %.2f", t1.value);
            printf("\nQuantidade: %d", t1.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            if(amount > t1.amount){
                printf("A quantidade desejada eh superior a oferecida atualmente. Por favor, escolha uma quantidade menor ou igual a ofertada.");
                exit(1);
            } else{
                value = t1.value * amount;
                t1.amount -= amount;
                printf("Compra realizada com sucesso.\n");
                printf("Quantidade: %d\n", amount);
                printf("Valor da transacao: %.2f", value);
            }

            break;
        }
        case 1:{
            int amount;
            float value;

            cleanScreen();
            header(t2.cod, ".");
            printf("\nValor: %.2f", t2.value);
            printf("\nQuantidade: %d", t2.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            if(amount > t2.amount){
                printf("A quantidade desejada eh superior a oferecida atualmente. Por favor, escolha uma quantidade menor ou igual a ofertada.");
                exit(1);
            } else{
                value = t2.value * amount;
                t1.amount -= amount;
                printf("Compra realizada com sucesso.\n");
                printf("Quantidade: %d\n", amount);
                printf("Valor da transacao: %.2f", value);
            }

            break;
        }
        case 2:{
            int amount;
            float value;

            cleanScreen();
            header(t3.cod, ".");
            printf("\nValor: %.2f", t3.value);
            printf("\nQuantidade: %d", t3.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            if(amount > t3.amount){
                printf("A quantidade desejada eh superior a oferecida atualmente. Por favor, escolha uma quantidade menor ou igual a ofertada.");
                exit(1);
            } else{
                value = t3.value * amount;
                t1.amount -= amount;
                printf("Compra realizada com sucesso.\n");
                printf("Quantidade: %d\n", amount);
                printf("Valor da transacao: %.2f", value);
            }

            break;
        }
        default:{
            printf("Opcao invalida.");
            break;
        }
    }
}

void sell(title t1, title t2, title t3){
    int option;
    cleanScreen();
    header(" Simulador de mercado de acoes ", ".");
    printList();
    printf("\nDigite o numero referente a acao desejada: ");
    scanf("%d", &option);

    switch (option){
        case 0:{
            int amount;
            float value;

            cleanScreen();
            header(t1.cod, ".");
            printf("\nValor: %.2f", t1.value);
            printf("\nQuantidade: %d", t1.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            value = t1.value * amount;
            t1.amount += amount;
            printf("Venda realizada com sucesso.\n");
            printf("Quantidade: %d\n", amount);
            printf("Valor da transacao: %.2f", value);
            
            break;
        }
        case 1:{
            int amount;
            float value;

            cleanScreen();
            header(t2.cod, ".");
            printf("\nValor: %.2f", t2.value);
            printf("\nQuantidade: %d", t2.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            value = t2.value * amount;
            t2.amount += amount;
            printf("Venda realizada com sucesso.\n");
            printf("Quantidade: %d\n", amount);
            printf("Valor da transacao: %.2f", value);
            
            break;
        }
        case 2:{
            int amount;
            float value;

            cleanScreen();
            header(t3.cod, ".");
            printf("\nValor: %.2f", t3.value);
            printf("\nQuantidade: %d", t3.amount);
            printf("\n Quantidade desejada: ");
            scanf("%d", &amount);

            value = t3.value * amount;
            t1.amount += amount;
            printf("Venda realizada com sucesso.\n");
            printf("Quantidade: %d\n", amount);
            printf("Valor da transacao: %.2f", value);
            
            break;
        }
        default:{
            printf("Opcao invalida.");
            break;
        }
    }
}

void cleanScreen(){
    #ifdef OS_Windows
    system("cls");
    #else
    system("clear");
    #endif 
}

int menu(){ 
    int option;

    header(" Simulador de mercado de acoes ", ".");
    printList();
    printf("\nEscolha uma das seguintes opcoes:\n\n[1] Comprar uma acao\n[2] Vender uma acao\n[0] Sair\n\n opcao: ");
    scanf("%d", &option);
    return option;
}