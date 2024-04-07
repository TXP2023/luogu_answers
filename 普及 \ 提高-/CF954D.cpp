//Fight Against Traffic
#include <vector>
#include <stdio.h>
#include <queue>
#define int_MAX 1e9+7

using namespace std;

typedef long long ll;

vector< vector< bool > > v;//邻接矩阵 有路为true 没有为false1
vector< ll > dits[2];//二维数组，来存储始发点和终到点到各个点的最短距离 其中始发为0 终到为1
ll n,m,F,T,ans = 0;

struct node
{
    ll to,length;
    bool operator <(const node& other) const{
        return length > other.length;
    }
};


inline void spfa(ll f,ll a)
{
    priority_queue< node > _queue;
    _queue.push({f,0});
    dits[a][f] = 0;
    while (!_queue.empty())
    {
        node f = _queue.top();
        _queue.pop();
        for (ll i = 0; i < n; i++)
        {
            if(v[f.to][i] == true && dits[a][i] > f.length+1)
            {
                dits[a][i] = f.length+1;
                _queue.push({i,dits[a][i]});
            }
        }
    }
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r",stdin);
    scanf("%lld%lld%lld%lld",&n,&m,&F,&T);
    F--;
    T--;
    v.resize(n);
    dits[0].resize(n,int_MAX);
    dits[1].resize(n,int_MAX);
    for (ll i = 0; i < n; i++)
    {
        v[i].resize(n,false);
    }
    for (ll i = 0; i < m; i++)
    {
        ll from,to;
        scanf("%lld%lld",&from,&to);
        v[--from][--to] = true;
        v[to][from] = true;
    }
    spfa(F,0);
    spfa(T,1);
    for (ll i = 0; i < n-1; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            if(!v[i][j])
            {
                if(dits[0][i]+dits[1][j]+1 >= dits[0][T] && dits[0][j]+dits[1][i]+1>=dits[0][T])
			    {
				    ans++;
                    v[i][j] = true;
                    v[j][i] = true;
			    }
            }
        }
        
    }
    printf("%lld\n",ans);
    return 0;
}
