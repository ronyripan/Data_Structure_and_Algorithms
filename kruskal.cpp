#include<bits/stdc++.h>

using namespace std;
vector< pair<int,pair<int,int> > >edge;
map<int,int>parent;
int ans,n,a;
void make_set(int a)
{
    parent[a] = a;
}
int find_parent(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}
void Union(int a,int b)
{
    int u = find_parent(a);
    int v = find_parent(b);
    if(u != v)
    {
        parent[u] = v;
    }
}
void kruskal()
{
    int edgecost = 0;
    sort(edge.begin(),edge.end());
    for(int i = 0; i < edge.size(); i++)
    {
        if(find_parent(edge[i].second.first) != find_parent(edge[i].second.second))
        {
            Union(edge[i].second.first,edge[i].second.second);
            edgecost += edge[i].first;
        }
    }
    cout << edgecost << endl;
}
int main()
{
        int m;
        scanf("%d %d",&n,&m);
        for(int j = 1; j <= n; j++) make_set(j);
        for(int j = 1; j <= m; j++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge.push_back({w,{u,v}});
        }

    kruskal();
    return 0;
}
