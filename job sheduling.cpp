#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int,pair<int,int> > p[n+1];
    int dmax = 0;
    for(int i = 1; i <= n; i++)
    {
        int deadline, profit;
        cin >> deadline >> profit;
        dmax = max(deadline,dmax);
        p[i] = {profit,{i,deadline}};
    }
    sort(p + 1, p + n + 1);
    int time[dmax + 1];
    for(int i = 1; i <= dmax; i++)
    {
        time[i] = 0;
    }
    for(int i = n; i >= 1; i--)
    {
        int deadline  = p[i].second.second;
        int profit = p[i].first;
        int jobid = p[i].second.first;
        for(int j = min(dmax,deadline); j >= 1; j--)
        {
            if(time[j] == 0)
            {
                time[j] = jobid;
                break;
            }
        }
    }
    for(int i = 1; i <= dmax; i++)
    {
        cout << time[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
5
2 60
1 100
3 20
2 40
1 20
*/
