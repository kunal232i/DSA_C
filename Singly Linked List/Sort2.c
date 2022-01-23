#include <stdio.h>
#include <stdlib.h>


int partition(struct Student A[],int low,int high)
{
    int pivot = A[low].rollNo;
    int i = low+1;
    int j = high;
    struct Student temp;

    while(1)
    {
        while(A[i].rollNo<pivot)
        {
            i++;
        }
        while(A[j].rollNo>pivot)
        {
            j--;
        }

        if(i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else
        {
            temp =A[j];
            A[j]= A[low];
            A[low] = temp;
            return j;
        }
    }
}

void Quicksort(struct Student A[],int low, int high)
{
    if(low<high)
    {
        int index = partition(A, low, high);
        Quicksort(A, low, index-1);
        Quicksort(A, index+1, high);
    }
}