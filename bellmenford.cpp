#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int main()
{
    int node,edge;
    cin >> node >> edge;
    int dist[node+1];
    pair<int,pair<int,int> >a[edge + 1];
    for(int i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u,{v,w}};
    }
    for(int i = 1; i <= node; i++)
    {
        dist[node] = INF;
    }
    for(int i = 1; i <= node-1; i++)
    {
        for(int j = 1; j <= edge; j++)
        {
            int u = a[j].first;
            if(i == 1 && j == 1) dist[u] = 0;
            int v = a[j].second.first;
            int w = a[j].second.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int j = 1; j <= edge; j++)
    {
        int u = a[j].first;
        int v = a[j].second.first;
        int w = a[j].second.second;
        if(dist[u] + w < dist[v])
        {
            cout << "NEGETIVE CYCLE DETECTED" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= node; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
