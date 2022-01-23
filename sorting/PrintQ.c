#include<stdio.h>
#include"Quicksort.c"

void Array(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }printf("\n");
}

int main()
{
    int a[]={48,50,12,5,3,1,17};
    int n =7;

    printf("unsorted array\n");
    Array(a, n);

    Quicksort(a, 0, 6);

    printf("sorted array\n");
    Array(a, n);
}