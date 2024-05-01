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
    ll volume,money;//对应消耗的体力和体积
};

vector< ll > dp;
ll V,N,C;

inline ll FindAnswers()
{
    ll ans = __LONG_LONG_MAX__;
    for (ll i = dp.size()-1; i >= 0 ; i--)
    {
        if (dp[i]>=V)
        {
            ans = std::min(ans,i);
        }
        
            
    }
    return (ans == __LONG_LONG_MAX__)? -1 : ans;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&V,&N,&C);
    dp.resize(C+1,0);
    for (ll i = 0; i < N; i++)
    {
        ll volume,money;
        scanf("%lld%lld",&money,&volume);
        for (ll j = C; j >= volume; j--)
        {
            dp[j] = std::max(dp[j],dp[j-volume] + money);
        }
    }
    switch (FindAnswers())
    {
    case -1:
        printf("Impossible\n");
        break;
    
    default:
        printf("%lld\n",C-FindAnswers());
        break;
    }
    return 0;
}
