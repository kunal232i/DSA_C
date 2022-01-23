#include <stdio.h>
#include <stdlib.h>

void deleteAtbeg()
{
    if(head==NULL)
        printf("\nList is empty");

    else{
    struct node *p;
    p=head;
    head=head->next;
    free(p);
    p=NULL;
    }
}

void deleteatend()
{
    if(head==NULL)
        printf("\nList is Empty");

    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {   
        struct node *p,*q;
        p=head;
        q=head;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
        p=NULL;
    }
    
}