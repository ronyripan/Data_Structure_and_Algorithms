#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a;
    cin >> b;
    int len1 = a.length();
    int len2 = b.length();
    int mat[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0 || j == 0)
            {
                mat[i][j] = 0;
                continue;
            }
            if(a[i-1] ==  b[j - 1]) mat[i][j] = mat[i - 1][j - 1] + 1;
            else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
        }
    }
    cout << mat[len1][len2] << endl;
    int i = len1;
    int j = len2;
    stack<char>s;
    while(1)
    {
        if(mat[i][j] == 0) break;
        if(mat[i][j] == mat[i-1][j-1]+1 && a[i-1] == b[j-1])
        {
            s.push(a[i-1]);
            i = i - 1;
            j = j - 1;
        }
        else
        {
            if(mat[i][j] == mat[i-1][j])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
