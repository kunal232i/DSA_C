#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void Meanu()
{
    p:
    
    printf( "\n--------------------\n"
            "1. Insert At Beginning\n"
            "2. Insert At End\n"
            "3. Insert At Index\n"
            "4. Search\n"
            "5. Delete At Beginning\n"
            "6. Delete At End\n"
            "7. Exit\n");
    int Choice;
    scanf("%d",&Choice);

    switch (Choice)
    {
    case 1:
        InsertAtBeg();
        display();
        break;
        
    case 2:
        InsertAtEnd();
        display();
        break;
        
    case 3:
        insertAtIndex();
        display();
        break;
       
    case 4:
        search();
        display();
        break;
        
    case 5:
        deleteAtbeg();
        display();
        break;
        
    case 6:
        deleteatend();
        display();
        break;
        
    case 7:
        printf("Thank you\n");
        exit(0);
        
    default:
        printf("\nInvalid Value\n");
        break;
        
    }
    getch();
    goto p;
}