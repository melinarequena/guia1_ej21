//
// Created by Administrador on 17/6/2023.
//

#ifndef GUIA1_EJ21_LISTADOBLE_H
#define GUIA1_EJ21_LISTADOBLE_H

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}Node;

typedef struct list{
    Node * header;
}List;

Node * newNode(int data);
List * newList();

void enlist(List * list, Node * nodeList);
void delete(List * list, int num);
void modify(List * list, int numOld, int numNew);
void order(List * list);
void invert(List * list);
void print(List * list);
#endif //GUIA1_EJ21_LISTADOBLE_H
