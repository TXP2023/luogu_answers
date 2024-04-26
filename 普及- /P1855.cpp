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
#define max std::max
#define min std::min

typedef long long ll;

struct data
{
    ll money, time;//金钱和时间
};

vector< vector< ll > >  dp; 
vector< data > data_s;
ll N,M,T;

inline void InitiAlize_V(vector< vector< ll > >* v,ll a,ll b)
{
    v->resize(a);
    for(ll i = 0; i < v->size(); ++i) 
    {  
        (*v)[i].resize(a, b);  
    }  
    return;
}

int main()
{
    scanf("%lld%lld%lld",&N,&M,&T);
    dp.resize(M+1);
    data_s.resize(N);
    InitiAlize_V(&dp,T+1,0);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld%lld",&data_s[i].money,&data_s[i].time);
    }
    for (ll i = 0; i < N; i++)//前i个愿望
    {
        for (ll j = M; j > 0; j--)//前j个金钱
        {
            for (ll k = T; k > 0; k--)//前k个时间
            {
                if (j>=data_s[i].money && k>=data_s[i].time)
                {
                    dp[j][k] = max(dp[j][k],dp[j-data_s[i].money][k-data_s[i].time]+1);
                }
            }
        }
    }
    printf("%lld\n",dp[M][T]);
    return 0;
}
