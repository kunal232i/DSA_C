#include <stdio.h>
#include <stdlib.h>

void search()
{
    struct node *temp, *r;
    int key;
    if (head == NULL)
        printf("LIst is Empty\n");
    else
    {
        printf("\nEnter the data : ");
        scanf("%d", &key);
        temp = head;
        int index = 1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("\nElement %d was found at index %d\n",key,index);
                break;
            }
            temp=temp->next;
            index++;
            if (temp == NULL)
            {
                printf("Element is not found\n");
            }
        }
    }
}