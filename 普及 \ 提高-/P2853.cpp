#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

vector< vector< ll > > nodes;
vector< ll > where,v;//奶牛分别在哪里？
vector< bool > vis;
ll K,N,M,ans = 0;

inline void DFS(ll k)
{
    for (ll i = 0; i < nodes[k].size(); i++)
    {
        if (!vis[nodes[k][i]])
        {
            vis[nodes[k][i]] = true;
            v[nodes[k][i]]++;
            DFS(nodes[k][i]);
        }
    }
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r",stdin);
    scanf("%lld%lld%lld",&K,&N,&M);
    nodes.resize(N);
    where.resize(K);
    vis.resize(N,false);
    v.resize(N,0);
    for (ll i = 0; i < K; i++)
    {
        scanf("%lld",&where[i]);
    }
    for (ll i = 0; i < M; i++)
    {
        ll from,to,length;
        scanf("%lld%lld",&from,&to);
        nodes[--from].push_back({--to});
    }
    
    for (ll i = 0; i < K; i++)
    {
        vis.resize(0);
        vis.resize(N,false);
        vis[where[i]-1] = true;
        v[where[i]-1]++;
        DFS(where[i]-1);
    }
    for (ll i = 0; i < N; i++)
    {
        if(v[i] == K)
            ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
