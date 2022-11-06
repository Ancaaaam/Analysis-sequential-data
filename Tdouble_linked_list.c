#include "Tdouble_linked_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void init(TDoubleLinkedList** list)
{
   *list=(TDoubleLinkedList*)malloc(sizeof(TDoubleLinkedList));
    (*list)->len=0;
    (*list)->head=NULL;
    (*list)->tail=NULL;
}

void add(TDoubleLinkedList** list, double data, int timestamp)
{
    node* temp;
    node* newnode=(node*)calloc(1,sizeof(node));
    newnode->data=data;
    newnode->timestamp=timestamp;
    newnode->next=NULL;
    if((*list)->head==NULL)
    {
        newnode->prev=NULL;
       (*list)->head=newnode;
       (*list)->tail=newnode;
       (*list)->len++;
    }
    else
    {
        newnode->prev=(*list)->tail;
            (*list)->tail->next=newnode;
            (*list)->tail=newnode;
        (*list)->len++;
    }
}

void removee(TDoubleLinkedList** list, int n)
{
    if(n<0||n>=(*list)->len)
       return;
     if(n==0)
        {
            node *temp=(*list)->head;
        (*list)->head=(*list)->head->next;
        (*list)->head->prev=NULL;
        free(temp);
        (*list)->len--;
    }
    else
    if(n==(*list)->len-1)
    {
        node *del=(*list)->tail;
       del=del->prev;
        node *temp=(*list)->tail;
        (*list)->tail->next=NULL;
        del->next=NULL;
        (*list)->tail=(*list)->tail->prev;
        free(temp);
        (*list)->len--;
    }
    else
     {
         int i;
         node *del=(*list)->head;
    for(i=0;i<n-1;i++)
           del=del->next;
    node *temp=del->next;
    del->next=del->next->next;
    del->next->prev=del;
    free(temp);
    (*list)->len--;
     }
}


void print_int_list(TDoubleLinkedList** list)
{
    node *temp=(*list)->head;
    int k=0;
    while(temp!=NULL&&k<(*list)->len)
    {
        printf("%d %.2lf\n", temp->timestamp,temp->data);
        temp=temp->next;
        k++;
    }
}

void eliberare(TDoubleLinkedList** lista)
{
    node *temp;
        while((*lista)->head!=NULL)
    {
        if((*lista)->head==(*lista)->tail)
        {
            temp=(*lista)->tail;
           (*lista)->head=NULL;
            (*lista)->tail=NULL;
            free(temp);
            (*lista)->len--;
        }
        else
        {
            temp=(*lista)->head;
            (*lista)->head=(*lista)->head->next;
            free(temp);
	        (*lista)->len--;
        }
    }
   free(*lista);
}

