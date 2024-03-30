#include <stdio.h>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct node
{
    ll to,length;
    bool operator <(const node &a)const{
		return length<a.length;
	}
};


vector< vector< node > > v_to,v_back;//记录结构体路径
vector< ll > length_to,length_back;//length_to为正向图，length_back为反向图；
ll N,M,ans = 0;//N个点 M条边

inline void SPFA_to()
{
    priority_queue< node> _queue;
    length_to[0] = 0;
    _queue.push({0,0});
    while(!_queue.empty())
    {
        ll nxt = _queue.top().to;
        _queue.pop();
        for (ll i = 0; i < v_to[nxt].size(); i++)
        {
            if(v_to[nxt][i].length + length_to[nxt] < length_to[v_to[nxt][i].to])
            {
                length_to[v_to[nxt][i].to] = v_to[nxt][i].length + length_to[nxt];
                _queue.push({v_to[nxt][i].to,length_to[v_to[nxt][i].to]});
            }
        }
        
    }
}

inline void SPFA_back()
{
    priority_queue< node> _queue;
    length_back[0] = 0;
    _queue.push({0,0});
    while(!_queue.empty())
    {
        ll nxt = _queue.top().to;
        _queue.pop();

        for(int i=0;i<v_back[nxt].size();i++)
        {
            if(length_back[v_back[nxt][i].to] > length_back[nxt] + v_back[nxt][i].length)
            {
                length_back[v_back[nxt][i].to] = length_back[nxt] + v_back[nxt][i].length;
                _queue.push({v_back[nxt][i].to,length_back[v_back[nxt][i].to]});
            }
        }
    }
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld",&N,&M);
    length_back.resize(N,1e9+7);
    length_to.resize(N,1e9+7);
    v_to.resize(N);
    v_back.resize(N);
    for(ll i = 0;i < M ;i++)
    {
        ll from,to,length;
        scanf("%lld%lld%lld",&from,&to,&length);
        v_to[--from].push_back({--to,length});//这个点可以到哪里？
        v_back[to].push_back({from,length});//那个点可以到这里？
    }
    SPFA_to();
    SPFA_back();
    for(ll i = 0;i < N ;i++)
    {
        ans += length_to[i] + length_back[i];
    }
    printf("%lld\n",ans);
    return 0;
}
