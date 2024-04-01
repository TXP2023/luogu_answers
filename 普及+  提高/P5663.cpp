//P5663 [CSP-J2019] 加工零件
// 版权所有 @TXP2023 www.luogu.com.cn
#include <bits/stdc++.h>
#define ll_MAX 1e9+7

using namespace std;

typedef long long ll;

struct node{
    ll to,op;//0为奇数 1为偶数
    bool operator < (const node &other) const { //dijkstra 贪心思路：距离短的优先
		return op < other.op;
	}
};

vector< vector< node > > v;
vector< ll > dis[2];
priority_queue< node > q;
ll N,M,Q;

inline void SPFA()
{
    q.push({0,0});
    dis[0][0] = 0;
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        for (ll i = 0; i < v[ now.to ].size(); i++)
        {
            if(dis[1^now.op][v[ now.to ][i].to] > 1 + dis[now.op][now.to])
            {
                dis[1^now.op][v[ now.to ][i].to] = 1 + dis[now.op][now.to];
                q.push({v[ now.to ][i].to,1^now.op});
            }
        }
    }
    return;
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&N,&M,&Q);
    v.resize(N+1);
    dis[0].resize(N,ll_MAX);
    dis[1].resize(N,ll_MAX);
    for(ll i=0 ;i < M ;i++)
    {
        ll from,to;
        scanf("%lld%lld",&from,&to);
        v[--from].push_back({--to,1});
        v[to].push_back({from,1});
    }
    SPFA();
    for(ll i=0 ;i < Q ;i++)
    {
        ll A,B;
        scanf("%lld%lld",&A,&B);
        A--;
        if(v[0].size() == 0)
        {
            printf("No\n");
            continue;
        }
        else
        {
            if (dis[B&1][A] > B) 
                printf ("No\n");
            else
                printf ("Yes\n");
        }
    }
    return 0;
}
