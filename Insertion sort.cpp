#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i ;
        while(value < a[j - 1] && j > 0)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = value;
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
    return 0;
}
