#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <set>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque

typedef long long ll;

vector< vector< ll > > dp,in;
ll n,ans = 0;//n个工厂

struct node
{
    ll x,y;//前往了x行y列的
};

inline void bfs()
{
    queue< node> _queue;
    _queue.push({0,0});
    dp[0][0] = in[0][0];
    while (!_queue.empty())
    {
        ll x = _queue.front().x,y = _queue.front().y;
        _queue.pop();
        if (x + 1 < n)//如果不是最后一行
        {
            if (dp[x][y] + in[x+1][y] > dp[x+1][y])
            {
                dp[x+1][y] = dp[x][y] + in[x+1][y];
                _queue.push({x+1,y});
            }
            if (dp[x][y] + in[x+1][y+1] > dp[x+1][y+1])
            {
                dp[x+1][y+1] = dp[x][y] + in[x+1][y+1];
                _queue.push({x+1,y+1});
            }
            
        }
    }
    return;
}

int main()
{
    scanf("%lld",&n);
    in.resize(n);
    dp.resize(n);
    for (ll i = 0; i < n; i++)
    {
        dp[i].resize(i+1,-1);
        in[i].resize(i+1);
        for (ll j = 0; j <= i; j++)
        {
            scanf("%lld",&in[i][j]);
        }
    }
    bfs();
    for (ll i = 0; i < n; i++)
    {
        if (ans < dp[n-1][i])
        {
            ans = dp[n-1][i];
        }
        
    }
    printf("%lld\n",ans);
    return 0;
}
