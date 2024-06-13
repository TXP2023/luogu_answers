#include <vector>
#include <stdio.h>
#include <algorithm>

#define mod 19650827

typedef long long ll;

std::vector< std::vector< ll > > dp;
std::vector< ll > input;
ll n;

int main()
{
    scanf("%lld", &n);

    //输入完美的队列 以及dp初始化
    input.resize(n);
    dp.resize(n, std::vector< ll >(n, 0));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &input[i]);
        dp[i][i] = 1;
    }
    
    //动归
    for (ll len = 1; len < n; len++)
    {
        for (ll i = 0; i+len < n; i++)
        {
            int end = i+len; //区间末尾下标
            if (input[end-1] < input[end]) //上一次放进去的是最后一个
            {
                dp[i][end] = dp[i][end-1];
            }

            if (input[i] < input[end] && len > 1)
            {
                dp[i][end] += dp[end-1][i];
            }

            dp[i][end] %= mod, dp[end][i] %= mod; 

            if (input[i] < input[i+1])
            {
                dp[end][i] += dp[end][i+1];
            }
            
            if (input[i] < input[end] && len > 1)
            {
                dp[end][i] += dp[i+1][end];
            }
            
            dp[i][end] %= mod, dp[end][i] %= mod; 
        }
    }
    
    printf("%lld\n", (dp[0][n-1]+dp[n-1][0])%mod);
    return 0;
}
