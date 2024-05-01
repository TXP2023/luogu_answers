// luogu题目： 装备运输 | P1794
// 作者：@TXP2023  www.luogu.com
// 上次更改时间：2024-5-1
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

struct MilitaryEquipment
{
    ll volume;//体积
    ll power;//重量
    ll weight;//威力
};

vector< vector< ll > > dp;//表示第i个体积，第j个重量的最大值
vector< MilitaryEquipment > Milyes;
ll V,G,N;

inline void initialize(ll a,ll b)
{
    dp.resize(a+1);
    for(int i=0;i<=a;i++)
    {
        dp[i].resize(b+1,0);
    }
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld\n%lld",&V,&G,&N);
    initialize(V,G);
    Milyes.resize(N);
    for(int i=0;i<N;i++)
    {
        scanf("%lld%lld%lld",&Milyes[i].weight,&Milyes[i].volume,&Milyes[i].power);
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = V; j >= Milyes[i].volume; j--)
        {
            for (ll k = G; k >= Milyes[i].power; k--)
            {
                dp[j][k] = std::max(dp[j][k],dp[j-Milyes[i].volume][k-Milyes[i].power]+Milyes[i].weight);
            }
        }
    }
    printf("%lld\n",dp[V][G]);
    return 0;
}
