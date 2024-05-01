#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <math.h>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque
#define max std::max

typedef long long ll;

struct data
{
    ll volume,money;
};

vector< data > data_s;
vector< ll > dp;
ll N,M;//宝物综素，车的重量

int main()  
{  
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);  
    scanf("%lld %lld", &N, &M);  
    dp.resize(M + 1, 0);  
  
    for (ll i = 0; i < N; i++)  
    {  
        ll volume, money, s;  
        scanf("%lld %lld %lld", &money, &volume, &s);  
        for (ll j = 1; j <= s; j *= 2) // 注意这里是 <= s 而不是 < s  
        {  
            if (j > s) j = s; // 确保不超过实际的数量 s  
            data_s.push_back({volume * j, money * j});  
            s -= j; // 更新剩余数量  
        }  
        if (s > 0) // 如果还有剩余数量  
        {  
            data_s.push_back({volume * s, money * s});  
        }  
    }  
  
    for (ll i = 0; i < data_s.size(); i++) // 枚举经过优化的物品  
    {  
        for (ll j = M; j >= data_s[i].volume; j--) // 逆序计算  
        {  
            dp[j] = max(dp[j], dp[j - data_s[i].volume] + data_s[i].money); // 动态转移方程  
        }  
    }  
  
    printf("%lld\n", dp[M]); // 输出  
    return 0;  
}
