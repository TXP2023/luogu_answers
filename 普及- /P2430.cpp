// luogu题目： P2430
// 作者：@TXP2023  www.luogu.com
// 上次时间：2024-5-1
// 语言：C++ 
// 标签：DP 背包
// 此代码创建于 2024-5-1
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
    ll time;//对应时间
    ll money;//对应可以获得的奖励
};

vector< ll > dp;
vector< data > data_S;
ll N,M,dpTime;//M对应题目 N对应知识点

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r",stdin);
    ll WkyLevel,Wlevel,level;
    scanf("%lld%lld",&WkyLevel,&Wlevel);
    level = Wlevel / WkyLevel;
    // delete &WkyLevel,&Wlevel;
    // delete[] &Wlevel;
    scanf("%lld%lld",&M,&N);
    ll wtime[N];
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld",&wtime[i]);
    }
    for (ll i = 0; i < M; i++)
    {
        ll time,money;
        scanf("%lld%lld",&time,&money);
        data_S.push_back(data{wtime[time-1]*level,money});
    }
    // delete &wtime;
    scanf("%lld",&dpTime);
    dp.resize(dpTime+1,0);
    for (ll i = 0; i < M; i++)
    {
        for (ll j = dpTime; j >= data_S[i].time; j--)
        {
            dp[j] = std::max(dp[j],dp[j-data_S[i].time]+data_S[i].money);
        }
    }
    printf("%lld",*(dp.end()-1));
    return 0;
}
