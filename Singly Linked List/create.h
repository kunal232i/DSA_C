#include <stdio.h>
#include <stdlib.h>

 void create()
 {
     struct node *temp,*r;
     int i,n;
     printf("\nEnter number of nodes : ");
     scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the Data for node : ");
            scanf("%d",&temp->data);
            temp->next=NULL;

            if(head==NULL)
                head=temp;
            else
            {
                r=head;
                while(r->next!=NULL)
                    r=r->next;
                    r->next=temp;
            }
        }
 }