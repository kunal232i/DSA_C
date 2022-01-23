#include<stdio.h>

void merge(int A[],int low,int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int B[100];

    while(i<=mid && j<=high)
    {
        if(A[i]>A[j])
        {
            B[k]=A[j];
            j++;k++;
        }
        else{
            B[k] = A[i];
            i++;k++;
        }
    }
    if(i>mid)
    {
        for(int l=j; l<=high; l++)
        {
            B[k]=A[l];
            k++;
        }
    }
    else{
        for(int l=i; l<=mid; l++)
        {
            B[k] = A[l];
            k++;
        }
    }

    for(int i=low; i<=high; i++)
    {
        A[i]=B[i];
    }

}

void MergeSort(int A[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;

        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}