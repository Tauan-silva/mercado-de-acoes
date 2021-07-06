#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
    #include<unistd.h>
    #include<stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    #include <windows.h>
#endif

typedef struct {
    char cod[6];
    int  amount;
    float value;
}title;

typedef struct node{
    title title;
    struct node *pLink;
} list;

list * createList(title value);
list * addItemList(title value);
list *fetchItemList(title value, list **previous);
title getValuesFromFile(char *fileName);
int isVoidList();
int removeItemList(title value);
int menu();
void sell();
void buy();
void printList();
void drawLine(char *caractere, int amount);
void header(char *heading, char *caractere);
void initialize(title title1, title title2, title title3);
void cleanScreen();
#endif