#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node * next;
}   Node;

int main()
{
    Node n1,n2;
    n1.valor = 10;
    n2.valor = 20;
    n1.next = &n2;
    printf("%d", n1.next->valor);
}
