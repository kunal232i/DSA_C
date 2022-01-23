#include <stdio.h>
#include <stdlib.h>

void InsertAtBeg()
{
    struct node *start;
    start = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element at beginning: ");
    scanf("%d", &start->data);
    start->next = head;
    head = start;
}


void InsertAtEnd()
{
    struct node *end, *temp;
    end = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Elementat End: ");
    scanf("%d", &end->data);
    end->next = NULL;

    if (head == NULL)
        head = end;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = end;
    }
}

void insertAtIndex()
{
    struct node *temp,*prev,*r;
    int i,n;
    printf("\nEnter the index: ");
    scanf("%d",&n);

    r=head;
    for(i=1;i<=n;i++)
    {
        if(i==n)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the element: ");
            scanf("%d",&temp->data);
            prev->next=temp;
            temp->next=r;
        }
        prev=r;
        r=r->next;
    }
}