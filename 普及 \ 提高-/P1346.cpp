#include <vector>
#include <queue>
#include <stdio.h>

typedef long long ll;

using namespace std;

struct node
{
    ll to,length;
    bool operator <(const node &a)const{
		return length<a.length;
	}
};

vector< vector< node > > nodes;
priority_queue< node > _queue;
vector< ll > ans;
ll N,F,T;

inline ll SPFA()
{
    _queue.push({--F,0});
    ans[F] = 0;
    while(!_queue.empty())
    {
        node Node = _queue.top();
        _queue.pop();
        for (ll i = 0; i < nodes[Node.to].size(); i++)
        {
            if(ans[nodes[Node.to][i].to] > Node.length + nodes[Node.to][i].length)
            {
                ans[nodes[Node.to][i].to] = Node.length + nodes[Node.to][i].length;
                _queue.push({nodes[Node.to][i].to,ans[nodes[Node.to][i].to]});
            }
        }
    }
    return ans[--T];
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&N,&F,&T);
    nodes.resize(N);
    ans.resize(N,1e9+7);
    for (ll i = 0; i < N; i++)
    {
        ll k;
        scanf("%lld",&k);
        for (ll j = 0; j < k; j++)
        {
            ll to;
            scanf("%lld",&to);
            if(--to != i)
            {
                switch (j)
                {
                case 0://
                    nodes[i].push_back({to,0});
                    break;
                
                default:
                    nodes[i].push_back({to,1});
                    break;
                }
            }
        }
    }
    ll answer = SPFA();
    switch (answer)
    {
    case 1000000007:
        printf("-1");
        break;
    
    default:
        printf("%lld",answer);
        break;
    }
    return 0;
}
