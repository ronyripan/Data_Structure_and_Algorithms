#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
const int node = 500;
vector<int>edge[node];
int cost[node][node];
int main()
{
    int n, m;
    cin >> n >> m;
    int taken[n + 1], dist[n + 1];
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        taken[i] = 0;
    }
    int s = 1;
    dist[s] = 0;
    priority_queue<pair<int,int>, vector< pair< int, int > >, greater<pair<int ,int> > > p;
    p.push({dist[s],s});
    int ans  = 0;
    while(!p.empty())
    {
        int u = p.top().second;
        int d = p.top().first;
        p.pop();
        if(taken[u] == 1) continue;
        taken[u] = 1;
        ans += d;
        for(int i = 0; i < edge[u].size(); i++)
        {
            int tmp = edge[u][i];
            if(taken[tmp] == 1) continue;
            if(cost[u][tmp] < dist[tmp])
            {
                dist[tmp] = cost[u][tmp];
                p.push({dist[tmp],tmp});
            }
        }
    }
    cout << ans << endl;
}
/*

6 9
1 2 6
1 5 4
2 3 1
3 6 2
6 4 3
4 5 14
2 5 7
3 5 8
3 4 5

*/
