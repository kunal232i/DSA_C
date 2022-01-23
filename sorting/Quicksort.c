
#include<stdio.h>
int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int i =low+1;
    int j =high;
    int temp;

    while(1)
    {
        while(a[i]<pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else{
            temp = a[j];
            a[j]= a[low];
            a[low] = temp;
            return j;
        }
        
    }
}

void Quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int index;
        index = partition(a, low, high);
        Quicksort(a, low, index-1);
        Quicksort(a, index+1,high);
    }
}