//有权有向图

#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#define ll long long

using namespace std;

struct  anode
{
    ll k,right;//走到了节点k,累计权重为right
};

vector< vector< anode > > v;
vector< ll > vis;
vector< bool > b;
queue< anode > nodes;
ll N,M,K,L;//N个点 M条无相边 K次询问 从点L开始

void BFS(ll l)
{
    //anode Node;//建立一个类型为anode的结构体为队列的首位
    //Node.k = l;
    //Node.right = 0;
    nodes.push({l,0});//压入队列
    while (!nodes.empty())//如果队列不为空
    {
        anode node;
        node = nodes.front();
        b[node.k] = false;
        nodes.pop();//弹出
        for (ll i = 0; i < v[node.k].size(); i++)
        {
            if((vis[ v[node.k][i].k ] == -1 || vis[v[node.k][i].k] > v[node.k][i].right+node.right) )//如果存在路径且
            {
                vis[v[node.k][i].k] = v[node.k][i].right+node.right;
                if(!b[v[node.k][i].k])
                {
                    nodes.push({v[node.k][i].k,v[node.k][i].right+node.right});
                }
            }
        }
    }
    1;
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&N,&M,&L);
    v.resize(N);
    b.resize(N,false);
    vis.resize(N,-1);
    for (ll i = 0; i < M; i++)
    {
        ll from,to,right;
        scanf("%lld%lld%lld",&from,&to,&right);
        if(from != to )
        {
            from--;
            to--;
            anode Anode;
            Anode.k = to;
            Anode.right = right;
            v[from].push_back(Anode);
        }
    }
    vis[--L] = 0;
    BFS(L);
    for (ll i = 0; i < N; i++)
    {
        //printf("%lld%c",vis[i],' ');
        switch (vis[i])
        {
        case -1:
            printf("%lld%c",2147483647,' ');
            break;
        
        default:
            printf("%lld%c",vis[i],' ');
            break;
        }
    }
    printf("\n");
    return 0;
}
