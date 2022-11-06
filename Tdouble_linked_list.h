#ifndef TDOUBLE_LINKED_LIST_H
#define TDOUBLE_LINKED_LIST_H

typedef struct node {
double data;
int timestamp;
struct node *next;
struct node *prev;
} node;

typedef struct TDoubleLinkedList {
node *head;
node *tail;
int len;
} TDoubleLinkedList;

void init(TDoubleLinkedList** list);

void add(TDoubleLinkedList** list, double data, int timestamp);

void removee(TDoubleLinkedList** list, int n);

void print_int_list(TDoubleLinkedList** list);

void eliberare(TDoubleLinkedList** lista);


#endif
