#include<bits/stdc++.h>
#define INF 1e15
#define ll long long
using namespace std;
const ll num = 100005;
vector<ll>edge[num];
vector<ll>cost[num];
//ll cost[100][100];
ll dist[num];
ll vis[num],n,parent[num];
map<ll,ll>ma;
void dijkstra()
{
    ll ans = 0;
    priority_queue<pair<ll,ll>, vector <pair<ll,ll> >, greater< pair < ll, ll > > > p;
    p.push({0,1});
    while(!p.empty())
    {
        ll u = p.top().second;
        p.pop();
        if(u == n) break;
        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll tmp = edge[u][i];
                if(dist[u] + cost[u][i] < dist[tmp])
                {
                    dist[tmp] = dist[u] + cost[u][i];
                    parent[tmp] = u;
                    p.push({dist[tmp],tmp});
                }

            }
        }
        cout << dist[n] << endl;
        ll k =n;
   stack<ll>vec;
    if(parent[k]==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        while(1)
        {
            vec.push(k);
            k = parent[k];
            if(k == 0)
                break;
        }
        while(!vec.empty())
        {
            cout<<vec.top()<<" ";
            vec.pop();
        }
    }
    cout << endl;
    }
int main()
{
    ll m;
    cin >> n >> m;
    dist[1] = 0;
    for(ll i = 2; i <= n; i++)
    {
        dist[i] = INF;
    }
    ll u,v,w;
    for(ll i = 1;i <= m; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(v);
        cost[u].push_back(w);
        edge[v].push_back(u);
        cost[v].push_back(w);
    }
    dijkstra();
    return 0;
}

