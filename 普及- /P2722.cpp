#include <stdio.h>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
typedef long long ll;  
  
struct stuff 
{  
    ll money, volume;  
};  
  
vector<ll> dp; // dp[i]表示容量为i的背包能装的最大价值  
vector<stuff> v; // 储存物品数据  
ll T, M; // T对应背包空间，M对应物品种类数量  
  
inline ll max(ll a, ll b) 
{  
    return (a > b) ? a : b;  
}  
  
int main() 
{  
    scanf("%lld%lld", &T, &M); // 输入背包容量和物品种类数量  
    v.resize(M);  
    dp.resize(T + 1, 0); // 初始化dp数组，全部为0  
  
    for (ll i = 0; i < M; i++) // 读取物品数据  
    { 
        scanf("%lld%lld", &v[i].money, &v[i].volume);  
    }  
  
    for (ll i = 0; i < M; i++) // 枚举每种物品  
    { 
        for (ll j = v[i].volume; j <= T; j++) // 从物品的体积开始正序遍历背包容量
        {   
            dp[j] = max(dp[j], dp[j - v[i].volume] + v[i].money); // 动态转移方程  
        }  
    }  
  
    printf("%lld\n", dp[T]); // 输出容量为T的背包能装的最大价值  
    return 0;  
}
