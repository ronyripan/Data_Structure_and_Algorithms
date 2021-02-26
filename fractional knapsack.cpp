#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cap;
    cin >> cap;
    pair<double, pair<int , int> > p[n+1];
    for(int i = 1; i <= n; i++)
    {
        int wt,value;
        cin >> wt >> value;
        double density = (value * 1.0) / (wt * 1.0);
        p[i] = {density,{wt,value}};
    }
    sort(p + 1, p + n + 1);
    double benifit = 0.0;
    double knapsack = 0.0;
    for(int i = n; i >= 1; i--)
    {
        int wt = p[i].second.first;
        int value = p[i].second.second;
        double density = p[i].first;
        if(wt + knapsack <= cap * 1.0)
        {
            knapsack = wt + knapsack;
            benifit += value;
        }
        else
        {
            benifit += (((cap - knapsack) * 1.0) * density);
            break;
        }
    }
    cout << benifit << endl;
    return 0;
}
/*
5
15
5 6
7 14
2 6
3 9
4 5
*/
