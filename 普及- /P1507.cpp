#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <string>
#include <math.h>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque
#define string std::string

typedef long long ll;

struct data
{
    ll h,t,k;
}data;

vector< vector< ll > > dp;
ll h,t,n;//最大体积，最大质量，食物数量

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&h,&t,&n);
    dp.resize(h+1);
    for(ll i=0;i<=h;i++)
    {
        dp[i].resize(t+1,0);
    }
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld",&data.h,&data.t,&data.k);
        for (ll j = h; j >= data.h; j--)//前j个体积
        {
            for (ll k = t; k >= data.t; k--)//前k个重量 倒序
            {
                dp[j][k] = std::max(dp[j][k],dp[j-data.h][k-data.t]+data.k);
            }
        }
    }
    printf("%lld\n",dp[h][t]);
    return 0;
}
