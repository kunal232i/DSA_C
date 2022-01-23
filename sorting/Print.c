
#include<stdio.h>
#include"MergeSort.c"


void Array(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[] = { 1, 20, 65, 73, 37, 45, 8};
    int n=7;

    printf("Unsorted Array\n");

    Array(A, n);

    MergeSort(A, 0, 6);

    printf("Sorted Array\n");

    Array(A, n);
    return 0;
}