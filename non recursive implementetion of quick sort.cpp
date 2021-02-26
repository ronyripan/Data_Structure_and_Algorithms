#include<iostream>
#include<algorithm>
#include<stack>
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
    stack<int>s;
    s.push(start);
    s.push(end);
    while(!s.empty())
    {

        end = s.top();
        s.pop();
        start = s.top();
        s.pop();
        int pIndex = partition(a,start,end);
        if(pIndex-1>start)
        {
            s.push(start);
            s.push(pIndex-1);
        }
        if(pIndex+1<end)
        {
            s.push(pIndex+1);
            s.push(end);
        }
    }
}
int main()
{
    int a[] = {10,1,9,2,8,3,7,4,6,5};
    quick_sort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}
