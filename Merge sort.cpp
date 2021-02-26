#include<bits/stdc++.h>

using namespace std;\
void Merge(int l[],int nl,int r[],int nr,int a[],int n)
{
    int i = 0, j = 0, k = 0;
    while(i < nl && j < nr)
    {
        if(l[i] <= r[j])
        {
            a[k] = l[i];
            i = i + 1;
        }
        else
        {
            a[k] = r[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < nl)
    {
        a[k] = l[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < nr)
    {
        a[k] = r[j];
        j = j + 1;
        k = k + 1;
    }
}
void mergesort(int a[],int n)
{
    if(n < 2) return;
    int mid = n / 2;
    int left[mid + 1];
    int right[n - mid + 1];
    for(int i = 0; i < mid ; i++) left[i] = a[i];
    for(int i = mid; i < n; i++) right[i-mid] = a[i];
    mergesort(left,mid);
    mergesort(right,n-mid);
    Merge(left,mid,right,n-mid,a,n);
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
    mergesort(a,n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
