//P4667 [BalticOI 2011 Day1] Switch the Lamp On
// 版权所有 @TXP2023 www.luogu.com.cn
// BFS算法
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

struct Node
{
    ll to,length;
};

vector< vector< Node > > v;
vector< ll > ans;

ll N,M;

inline void BFS()
{
    deque< Node > q;
    q.push_back({0,0});
    ans[0] = 0;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop_front();
        for (ll i = 0; i < v[now.to].size(); i++)
        {
            if(ans[v[now.to][i].to] > v[now.to][i].length + now.length)
            {
                ans[v[now.to][i].to] = v[now.to][i].length + now.length;
                switch(v[now.to][i].length)
                {
                case 1:
                    q.push_back({v[now.to][i].to,ans[v[now.to][i].to]});
                    break;

                case 0:
                    q.push_front({v[now.to][i].to,ans[v[now.to][i].to]});
                    break;
                }
            }
        }
    }
    //printf("%lld\n",ans[ans.size() - 1]);
    switch (ans[ans.size() - 1])
    {
    case 1000000007:
        printf("NO SOLUTION");
        break;
    
    default:
        printf("%lld\n",ans[ans.size() - 1]);
        break;
    }
    return;
}

int main()
{
     //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld",&N,&M);
    v.resize((N+1)*(M+1));//因为是二维的所以需要加1
    ans.resize((N+1)*(M+1),1e9+7);
    for (ll i = 0; i < N; i++)
    {
        int x,y;
        char in;
        for(ll j = 0; j < M; j++)
        {
            cin>>in;
            x = i*(M+1) + j;
            switch (in)
            {
            case '/':
                x++;
                y = (i+1)*(M+1) + j;
                v[x].push_back({y,0});
                v[y].push_back({x,0});
                v[x-1].push_back({y+1,1});
                v[y+1].push_back({x-1,1});
                break;
            
            default:
                y = (i+1)*(M+1) + j +1;
                v[x].push_back({y,0});
                v[y].push_back({x,0});
                v[x+1].push_back({y-1,1});
                v[y-1].push_back({x+1,1});
                break;
            }
        }
    }
    BFS();
    return 0;
}
