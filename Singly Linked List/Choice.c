#include<stdio.h>
#include<stdlib.h>


void students(struct Student A[], int n)
{
    printf("Students are \n");
    for (int i = 0; i < n; i++)
    {
        printf("Name %s\n"
               "Roll No %d\n",
               A[i].name, A[i].rollNo);
    }
}

void Choice(struct Student A[], int n)
{
    printf("Enter sort algo\n"
           "1. Merge Sort\n"
           "2. Quick Sort\n"
           "3. Exit\n");
    int option = 3;

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        MergeSort(A, 0, n - 1);
        students(A, n);
        break;
    case 2:
        Quicksort(A, 0, n - 1);
        students(A, n);
        break;
    case 3:
        exit(0);
        return;
    default:
        break;
    }
}