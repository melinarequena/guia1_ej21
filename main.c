#include <stdio.h>
#include "ListaDoble.h"

int main() {
    List * list = newList();
    enlist(list, newNode(1));
    enlist(list, newNode(2));
    enlist(list, newNode(3));
    enlist(list, newNode(4));
    enlist(list, newNode(5));
    enlist(list, newNode(6));
    enlist(list, newNode(7));
    enlist(list, newNode(8));

    print(list);
    invert(list);
    print(list);

}
