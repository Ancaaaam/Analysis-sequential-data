#include "functii.h"

#include "Tdouble_linked_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double average(node* p)
{
    double s=0.00;
    int k=5;
    while(k!=0)
    {
        s=s+p->data;
        k--;
        p=p->next;
    }
    s=(double)s/5;
    return s;
}
double deviation(node* p, double ave)
{
    double s=0.00;
    int k=5;
    while(k!=0)
    {
        double spar=(p->data-ave)*(p->data-ave);
        s+=spar;
        k--;
        p=p->next;
    }
    s=(double)s/5;
    s=(double)sqrt(s);
    return s;
}

double sortare(TDoubleLinkedList** lista) //sortare pentru e2
{
    int i,jj;
    double aux;
    node* p=(*lista)->head;
    for(i=1;i<=4;i++)
    {
         node* temp=p->next;
        for(jj=i+1;jj<=5;jj++)
       {
           if(p->data>temp->data)
        {
            aux=p->data;
            p->data=temp->data;
            temp->data=aux;
        }
        temp=temp->next;
       }
       p=p->next;
    }
    return (*lista)->head->next->next->data;
}


double m_arit(TDoubleLinkedList** lista)
{
    node* p=(*lista)->head;
    int i;
    double val,suma=0.00;
    for(i=1;i<=5;i++)
    {
        suma=suma+p->data;
        p=p->next;
    }
    val=(double)suma/5.00;
    return val;
}

void sortare_st(TDoubleLinkedList** lista) //sortare pt st
{
    node* x;
    node* y;
    for(x=(*lista)->head;x!=(*lista)->tail;x=x->next)
       for(y=x->next;y!=NULL;y=y->next)
            if(x->data>y->data)
            {
                double data;
                data=x->data;
                x->data=y->data;
                y->data=data;
            }
}
