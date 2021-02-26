#include<bits/stdc++.h>

using namespace std;
int tree[100];
void InsHeap(int item,int n)
{
    int ptr = n;
    while(ptr >= 1)
    {
        int par = floor(ptr/2);
        if(item <= tree[par])
        {
            tree[ptr] = item;
            return;
        }
        tree[ptr] = tree[par];
        ptr = par;
    }
    tree[1] = item;
    return;
}
void DelHeap(int n)
{
    int item = tree[1];
    int last = tree[n];
    int ptr = 1;
    int left = 2;
    int right = 3;
    cout << tree[1] << " ";
    while(right <= n)
    {
        if(last >= tree[left] && last >= tree[right])
        {
            tree[ptr] = last;
            return;
        }
        if(tree[left] >= tree[right])
        {
            tree[ptr] = tree[left];
            ptr = left;
        }
        else
        {
            tree[ptr] = tree[right];
            ptr = right;
        }
        left = 2 * ptr;
        right = left + 1;
    }
    if(left == n && last < tree[left])
    {
        ptr = left;
    }
    tree[ptr] = last;
    return;
}
int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        InsHeap(a[i],i);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    while(n >= 1)
    {
        DelHeap(n);
        n--;
    }
}
