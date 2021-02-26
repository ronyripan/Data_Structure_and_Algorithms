#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,cap;
    cin >> n >> cap;
    int wt[n+1],val[n+1];
    for(int i = 1; i <= n; i++) cin >> wt[i];
    for(int i = 1; i <= n; i++) cin >> val[i];
    int mat[n+1][cap+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= cap; j++)
        {
            if(j == 0 || i == 0) mat[i][j] = 0;
            else if(wt[i] <= j)
            {
                mat[i][j] = max(val[i]+mat[i-1][j - wt[i]],mat[i-1][j]);
            }
            else mat[i][j] = mat[i - 1][j];
        }
    }
    cout << mat[n][cap] << endl;
    int i = n;
    int j = cap;
    while(1)
    {
        if(mat[i][j] == 0) return 0;
        if(mat[i][j] == mat[i-1][j])
        {
            i = i - 1;
        }
        else
        {
            cout << wt[i] << " " << val[i] << endl;
            cap -= wt[i];
            i = i - 1;
            j  = cap;
        }
    }
    return 0;
}
/*
4 7
1 3 4 5
1 4 5 7
*/

