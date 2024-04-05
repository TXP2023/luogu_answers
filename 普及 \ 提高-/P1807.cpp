//有权有向图

#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#define ll long long

using namespace std;

struct  anode
{
    ll k,length;//走到了节点k,累计权重为length
};

vector< vector< anode > > v;
vector< ll > dis;
queue< anode > nodes;
ll N,M;//N个点 M条无相边 K次询问 从点L开始

void SPFA(ll l)
{
    dis[l] = 0;
    nodes.push({l,0});//压入队列
    while (!nodes.empty())//如果队列不为空
    {
        anode node;
        node = nodes.front();
        nodes.pop();//弹出
        for (ll i = 0; i < v[node.k].size(); i++)
        {
            if(dis[v[node.k][i].k] == -1 || dis[v[node.k][i].k] < v[node.k][i].length + node.length) // 如果尚未找到路径或存在更长的路径//如果存在路径且
            {
                dis[v[node.k][i].k] = v[node.k][i].length+node.length;
                nodes.push({v[node.k][i].k,v[node.k][i].length+node.length});
            }
        }
    }
    return;
}

int main()
{
    //freopen("D:\\SHU_RU.in","r",stdin);
    scanf("%lld%lld",&N,&M);
    v.resize(N);
    dis.resize(N,-1);
    for (ll i = 0; i < M; i++)
    {
        ll from,to,length;
        scanf("%lld%lld%lld",&from,&to,&length);
        v[--from].push_back({--to,length});
    }
    SPFA(0);
    printf("%lld",dis[N-1]);
    //printf("\n");
    return 0;
}
