#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[],int start,int end)
{
    int pivot = a[end];
    int pIndex = start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[end],a[pIndex]);
    return pIndex;
}
void quick_sort(int a[],int start,int end)
{
    if(start<end)
    {
        int pIndex = partition(a,start,end);
        quick_sort(a,start,pIndex-1);
        quick_sort(a,pIndex+1,end);
    }
}
int main()
{
    int a[] = {1,0,2,3,6,7,4,5,8,9};
    quick_sort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}
