#include <stdio.h>
#include <stdlib.h>

void display()
{
    struct node *temp;

    if (head == NULL)
        printf("\nList Is Empty");

    else
    {
        printf("---------Linked List---------\n");
        temp = head;
        while (temp != NULL)
        {
            printf("              "
                   "%d\n",
                   temp->data);
            temp = temp->next;
        }
    }
}