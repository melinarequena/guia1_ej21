//
// Created by Administrador on 17/6/2023.
//

#include "ListaDoble.h"
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int data) {
    Node * aux = NULL;
    aux = malloc(sizeof(Node));
    if(aux == NULL){
        printf("Error\n");
        exit (-1);
    }else{
        aux->data = data;
        aux->next = NULL;
        aux->prev = NULL;

        return aux;
    }
}

List *newList() {
    List * aux = NULL;
    aux = malloc(sizeof(List));
    if(aux == NULL){
        printf("Error\n");
        exit (-1);
    }else{
        aux->header = NULL;
        return aux;
    }
}

void enlist(List *list, Node *nodeList) {
    if(list->header == NULL){
        list->header = nodeList;
    }else{
        Node * aux = list->header;
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nodeList;
        nodeList->prev = aux;
        nodeList->next = NULL;
    }
}

void delete(List *list, int num) {
    Node * aux = list->header;
    while (aux != NULL && aux->data != num) {
        aux = aux->next;
    }
    if(aux == NULL) {
        printf("El elemento no esta en la lista\n");
    }else{
    if(aux->next == NULL){ // last on the list
        aux->prev = NULL;
        free(aux);
    }else{
        if(aux->prev == NULL){// header
            list->header = aux->next;
            aux->next->prev = NULL;
            free(aux);
        }else{ // middle
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
        }
    }
}
print(list);
}

void modify(List *list, int numOld, int numNew) {
    Node * aux = list->header;
    while (aux != NULL && aux->data != numOld){
        aux = aux->next;
    }
    if(aux->data == numOld){
        aux->data = numNew;
        print(list);
    }else{
        if(aux != NULL){
            printf("\nThe number is not on the list\n");
        }
    }
}

void print(List *list) {
    Node * aux = list->header;
    printf("\nLista:\n");
    while (aux != NULL) {
        printf("%d -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL");
}

void invert(List *list) {
    Node * first = list->header;
    Node * last = list->header;
    while (last->next != NULL) {
        last = last->next;
    }
    Node * aux = last;
    while(aux != first) {
        aux = aux->prev;
        last->next = list->header;
        list->header->prev = last;
        last->prev = NULL;
        aux->next = NULL;
        list->header = last;
        last = aux;
    }
}
