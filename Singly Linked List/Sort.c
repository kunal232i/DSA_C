#include<stdio.h>
#include<stdlib.h>


void merge(struct Student A[],int low,int mid,int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    struct Student B[(high- low)+1];

    while(i<= mid && j<=high)
    {
        if(A[i].rollNo>A[j].rollNo)
        {
            B[k] = A[j];
            j++;k++;
        }
        else
        {
            B[k] = A[i];
            i++;k++;
        }
    }

    if(i>mid)
    {
        for(int l=j; l<=high; l++)
        {
            B[k] = A[l];
            k++;
        }

    }
    else
    {
        for(int l=i; l<=mid; l++)
        {
            B[k] = A[l];
            k++;
        }
    }
    for(int i=low; i<=high; i++)
    {
        A[i] =B[i];
    }
    
}

void MergeSort(struct Student A[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}