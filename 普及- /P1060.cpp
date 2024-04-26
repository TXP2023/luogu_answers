#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <assert.h>
#include <math.h>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque
#define max std::max

typedef long long ll;

struct stuff
{
    ll Volume,Importance;//价格，重要程度
    
};

vector< stuff > s;
vector< ll  > dp;
ll N,M;//对应钱数，物品个数

int main()
{
    scanf("%lld%lld",&N,&M);
    dp.resize(N,0);
    s.resize(M);
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld%lld",&s[i].Volume,&s[i].Importance);
    }
    for (ll i = 0; i < M; i++) //前i+1个物品
    {
        for (ll j = N-1; j >= s[i].Volume; j--)//花费前j+1的钱数
        {
            if (s[i].Volume <= j)
            {
                dp[j] = max(dp[j],dp[j-s[i].Volume]+(s[i].Volume * s[i].Importance));
            }
            else
            {
                dp[j] = dp[j-1];
            }
        }
    }
    printf("%lld\n",*(dp.end()-1));
    return 0;
}
