#include<bits/stdc++.h>

using namespace std;
int Partition(int a[],int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for(int i = start; i < end; i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[pIndex],a[i]);
            pIndex++;
        }
    }
    swap(a[end],a[pIndex]);
    return pIndex;
}
void quickSort(int a[],int start,int end)
{
    if(start < end)
    {
        int pIndex = Partition(a,start,end);
        quickSort(a,start,pIndex-1);
        quickSort(a,pIndex+1,end);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a,0,n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
