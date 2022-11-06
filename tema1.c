#include "Tdouble_linked_list.h"
#include "functii.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(int argc, char *argv[])
{
    int i,h;
    int n,timestamp,timestamp_imp;
    double x,val_mij;
    TDoubleLinkedList *lista;
    TDoubleLinkedList *listacopy;
   for(i=1;i<argc;i++)
  { 
    if(strcmp(argv[i],"--e1")==0) //caz e1
    {
        TDoubleLinkedList *listafinal;
        if(i==1)
            {
                //initializam lista si listacopy
                scanf("%d", &n);
                init(&lista);
                init(&listacopy);
                for(h=0;h<n;h++)
                {
                    scanf("%d",&timestamp);
                    scanf("%lf", &x);
                    add(&lista,x,timestamp);
                }
            }
        init(&listafinal);
        int j;
        //daca nu suntem la primul argument n este listacopy->len
        if(i!=1)
            n=listacopy->len;
        //cautam elementele ce trebuie sterse si le salvam in listafinal
        for(h=2;h<=n-3;h++)
        {
            j=h-2;
            node *p;
            if(i==1)
                p=lista->head;
            else
                p=listacopy->head;
            //mergem la inceputul secventei de 5 elemente
            while(j!=0)
            {
                p=p->next;
                j--;
            }
            float ave=0.00,dev;
            ave=average(p);
            dev=deviation(p,ave);
            int ii=2;
            //ajungem la mijlocul secventei de 5 elemente
            while(ii!=0)
            {
                p=p->next;
                ii--;
            }
            if(!(ave-dev<=p->data&&ave+dev>=p->data))
                add(&listafinal,p->data,p->timestamp);
        }
        node *temp1=listafinal->head;
        while(temp1!=NULL)
        {
            node *temp;
            if(i==1)
                temp=lista->head;
            else
                temp=listacopy->head;
            int k=0;
            //cautam pozitia fiecarui element din listafinal in temp
            while(temp1->data!=temp->data)
                {
                    temp=temp->next;
                    k++;
                }
            //stergem elementul de pe pozitia k
            if(i==1)
                removee(&lista,k);
            else
                removee(&listacopy,k);
            temp1=temp1->next;
            n--;
        }
        //daca suntem la primul argument salvam lista in listacopy
        //listacopy va deveni input-ul pt urmatorul argument
        if(i==1)
        {
            node *temp=lista->head;
            for(h=0;h<lista->len;h++)
            {   
                add(&listacopy,temp->data,temp->timestamp);
                temp=temp->next;
            }
        } 
        //daca suntem la argumentul final afisam listacopy
        if(i==argc-1)
        {
            printf("%d\n",listacopy->len);
            print_int_list(&listacopy);
            eliberare(&listacopy);
        }
        if(i==1)
        eliberare(&lista);
        eliberare(&listafinal);
        }
    if(strcmp(argv[i],"--e2")==0||strcmp(argv[i],"--e3")==0)
    {
        int caz;
        if(strcmp(argv[i],"--e2")==0)
        caz=2;
        else
        caz=3;
        TDoubleLinkedList *listafinal;
        if(i==1)
            {
                scanf("%d", &n);
                init(&lista);
                init(&listacopy);
                for(h=0;h<n;h++)
                {
                    scanf("%d",&timestamp);
                    scanf("%lf", &x);
                    add(&lista,x,timestamp);
                } 
            }
        init(&listafinal);
        if(i!=1)
            n=listacopy->len;
        int j;
        for(h=2;h<=n-3;h++)
        {
            j=h-2;
            node *p;
            if(i==1)
                p=lista->head;
            else
                p=listacopy->head;
            while(j!=0)
            {
                p=p->next;
                j--;
            }
            node* pp=p;
            TDoubleLinkedList *lista2;
            init(&lista2);
            int ii;
            //adaugam in lista2 urmatoarele 5 elemente din p ca sa putem lucra pe ele
            //fara sa afectam lista originala
            for(ii=1;ii<=5;ii++)
            {
                add(&lista2,p->data,p->timestamp);
                p=p->next;
            }
            if(caz==2)
                val_mij=sortare(&lista2); //daca argumentul e e2
            else
                val_mij=m_arit(&lista2); //daca argumentul e e3
            ii=2;
            //ajungem la mijlocul secventei de 5 elementele
            while(ii!=0)
            {
                pp=pp->next;
                ii--;
            }
            timestamp_imp=pp->timestamp;
            add(&listafinal,val_mij,timestamp_imp);
            eliberare(&lista2);
        }
        //eliberam continutul lui listacopy ca sa umplem lista cu elementele lui listafinal
        if(listacopy->len>0)
        {       
            eliberare(&listacopy);
            init(&listacopy);
        }
        node* temp=listafinal->head;
        for(h=0;h<listafinal->len;h++)
        {
            add(&listacopy,temp->data,temp->timestamp);
            temp=temp->next;
        }
        if(i==argc-1)
            {
                printf("%d\n",listacopy->len);
                print_int_list(&listacopy);
                eliberare(&listacopy);
            }
        if(i==1)
            eliberare(&lista);
        eliberare(&listafinal);
    }
    if(strcmp(argv[i],"--u")==0)
    {
        if(i==1)
        {
            scanf("%d", &n);
            init(&lista);
            init(&listacopy);
            for(h=0;h<n;h++)
            {
                scanf("%d",&timestamp);
                scanf("%lf", &x);
                add(&lista,x,timestamp);
            }  
        }
        else
            n=listacopy->len;
        node* p;
        if(i==1)
            p=lista->head;
        else
            p=listacopy->head;
        p=p->next;
        for(h=1;h<n;h++)
        {
            if((p->timestamp-p->prev->timestamp>=100)&&(p->timestamp-p->prev->timestamp<=1000))
            {
                //modificam timestamp-ul si data daca se satisfac conditiile
                p->timestamp=(p->timestamp+p->prev->timestamp)/2.00;
                double suma=p->data+p->prev->data;
                p->data=(double)suma/2.00;
            }
            if((p->prev->timestamp-p->timestamp>=100)&&(p->prev->timestamp-p->timestamp<=1000))
            {
                p->timestamp=(p->timestamp+p->prev->timestamp)/2.00;
                double suma=p->data+p->prev->data;
                p->data=(double)suma/2.00;
            }
            p=p->next;
        }
        if(i==1)
        {
            node *temp=lista->head;
            for(h=0;h<lista->len;h++)
            {   
                add(&listacopy,temp->data,temp->timestamp);
                temp=temp->next;
            }
        } 
        if(i==argc-1)
        {
            printf("%d\n",listacopy->len);
            print_int_list(&listacopy);
            eliberare(&listacopy);
        }
        if(i==1)
            eliberare(&lista);
        }
    if(strcmp(argv[i],"--c")==0)
    {
        TDoubleLinkedList *listafinal;
        if(i==1)
            {
                scanf("%d", &n);
                init(&lista);
                init(&listacopy);
                for(h=0;h<n;h++)
                {
                    scanf("%d",&timestamp);
                    scanf("%lf", &x);
                    add(&lista,x,timestamp);
                }  
            }
        init(&listafinal);
        if(i!=1)
            n=listacopy->len;
        node *p;
        if(i==1)
            p=lista->head;
        else
            p=listacopy->head;
        //adaugam in listafinla primele 2 numere din lista
        add(&listafinal,p->data,p->timestamp);
        add(&listafinal,p->next->data,p->next->timestamp);
        p=p->next->next;
        double w0=0.0701754386;
        //0.1/(0.1+0.9*0.25+0.1+0.9+0.1);
        double w1=0.2280701754;
        //0.325/(0.1+0.9*0.25+0.1+0.9+0.1);
        double w2=0.701754386;
        //1/(0.1+0.9*0.25+0.1+0.9+0.1);
        int poz=-5;
        for(h=2;h<n-3;h++)
        {
            add(&listafinal,p->data,p->timestamp); //adaugam marginea inferioara din interval
            if(p->next->timestamp-p->timestamp>=1000)
            {
                double left2,left1,left0,right0,right1,right2;
                if(h-poz==1)
                {
                    //caz in care fix inainte de marginea inferioara a intervalul in care suntem
                    //a mai fost un interval in care au fost adaugate elemente
                    poz=-1;
                    left0=listafinal->tail->prev->prev->data;
                    left1=listafinal->tail->prev->data;
                }
                else
                if(h-poz==2)
                {
                    //caz in care elementul anterior anterior de marginea inferioara a intervalului in care suntem
                    //este marginea superioara a unui interval in care au fost adaugate elemente
                    poz=-1;
                    left0=listafinal->tail->prev->prev->data;
                    left1=p->prev->data;
                }
                else
                {
                    left0=p->prev->prev->data;
                    left1=p->prev->data;
                }
                left2=p->data;
                right0=p->next->next->next->data;
                right1=p->next->next->data;
                right2=p->next->data;
                timestamp_imp=p->timestamp+200;
                while(timestamp_imp<p->next->timestamp)
                {
                    //aflam C si noua valoare pe care o obtinem si o adaugam in listafinal
                    double C=(double)(timestamp_imp-p->timestamp)/(p->next->timestamp-p->timestamp);
                    double val=(double)(double)(1-C)*(double)(left0*w0+left1*w1+left2*w2)+(double)C*(double)(right0*w0+right1*w1+right2*w2);
                    add(&listafinal,val,timestamp_imp);
                    timestamp_imp=timestamp_imp+200;
                }
                poz=h;
            }
            p=p->next;
        }
        //adaugam in listafinal ultimile 3 elemente din lista orginala
        add(&listafinal,p->data,p->timestamp);
        add(&listafinal,p->next->data,p->next->timestamp);
        add(&listafinal,p->next->next->data,p->next->next->timestamp);
        if(listacopy->len>0)
        { 
            eliberare(&listacopy);
            init(&listacopy);
        }
        node *temp=listafinal->head;
        for(h=0;h<listafinal->len;h++)
        {
            add(&listacopy,temp->data,temp->timestamp);
            temp=temp->next;
        }
        if(i==argc-1)
            {
                printf("%d\n",listacopy->len);
                print_int_list(&listacopy);
                eliberare(&listacopy);
            }
        if(i==1)
            eliberare(&lista);
        eliberare(&listafinal);
        }
    if(argv[i][2]=='s'&&argv[i][3]=='t')
    {
        int l=strlen(argv[i]);
        l-=4; //scadem 4 pt ca primele 4 caractere din argv[i] sunt --st
        int k=4,eps=0;
        //aflam in eps lumgimea intervalului
        while(l>0)
        {
            int a=argv[i][k]-'0';
            eps=eps*10+a;
            l--;
            k++;
        }
        scanf("%d", &n);
        init(&lista);
        for(h=0;h<n;h++)
        {
            scanf("%d",&timestamp);
            scanf("%lf", &x);
            add(&lista,x,timestamp);
        } 
        sortare_st(&lista);
        int inc=round(lista->head->data); //aproximam aici
        if(inc>lista->head->data&&lista->head->data<0) //daca lista->head este negativ mai scadem -1 din inc
            inc-=1;
        int sf=inc+eps;
        //inc si sf reprezinta marginea inferioara si superioara a intervalului in care cautam numere
        node *p=lista->head;
        while(inc<lista->tail->data&&p!=NULL)
        {
            //calculam nr de nr al numerelor incluse intre inc si sf
            int ap=0;
            while(p->data<=sf&&p!=NULL)
                if(inc<=p->data&&p->data<=sf&&p!=NULL)
                    {
                        ap++;
                        if(p->next!=NULL)
                        p=p->next;
                        else
                        break;
                    }
                else
                    break;
            if(ap!=0) //daca am gasut din lista numere intre inc si sf afisam
            printf("[%d, %d] %d\n", inc, sf, ap);
            inc=sf;
            sf+=eps;
        }
        eliberare(&lista);
    }
  }
   return 0;
}
