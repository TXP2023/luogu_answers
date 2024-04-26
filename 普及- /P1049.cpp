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

typedef long long ll;

vector< vector< ll > > dp;
vector< ll > ll_v;
ll V,N;

inline ll max(ll a, ll b) 
{
    return a > b? a : b;
}

int main()
{
    scanf("%lld%ld",&V,&N);
    ll_v.resize(N);
    dp.resize(N+1);
    dp[0].resize(V+1,0);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld",&ll_v[i]);
        dp[i+1].resize(V+1,0);   
    }

    for (ll i = 1; i < N+1; i++)//前i个东西
    {
        for (ll j = 1; j < V+1; j++)//前j个空间
        {
            if (ll_v[i-1] > j)
            {
                dp[i][j] = dp[i-1][j]; 
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-ll_v[i-1]]+ll_v[i-1]);
            }
        }
    }
    printf("%lld",V-*(dp[N].end()-1));
    return 0;
}
