#include<stdio.h>
#include<stdlib.h>
#include"Student.h"
#include "Sort.c"
#include "Sort2.c"
#include "Choice.c"


void main()
{
    int count = 0;
    printf("number of students - ");
    scanf("%d", &count);
    printf("\n");

    struct Student A[count];
    for (int i = 0; i <count; i++)
    {
        printf("Enter Details %d\n",i+1);
        printf("Name - ");
        getchar();
        gets(A[i].name);

        printf("Roll no - ");
        scanf("%d", &A[i].rollNo);
        printf("\n");
    }
    
    Choice(A, count);
}

