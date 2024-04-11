#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

typedef long long ll;

struct node
{
    ll to,length;
    bool operator <(const node &other)const{
		return length > other.length;
	}
};

std::vector< std::vector< node > > nodes;
std::vector< ll > money,money_2;//money是用来二分的 money_2是用来比较这个点可不可以走的
ll n,m,d,first_money,last_money,ans = 9223372036854775807;

bool SPFA(ll max)//false为当前max无意义 true反之
{
    if(first_money<= max && last_money<= max)
    {
        
        std::priority_queue< node > _queue;
        std::vector< ll > v_ans;
        v_ans.resize(n,-1);
        v_ans[0] = d;
        _queue.push({0,d});
        while (!_queue.empty())
        {
            
            if(v_ans[n-1]!=-1)
                break;
            
            node now = _queue.top();
            _queue.pop();
            for (ll i = 0; i < nodes[now.to].size(); i++)
            {
                if (now.length - nodes[now.to][i].length >= 0 && v_ans[nodes[now.to][i].to] < now.length - nodes[now.to][i].length && money_2[ nodes[now.to][i].to ]<= max)
                {
                    v_ans[nodes[now.to][i].to] = now.length - nodes[now.to][i].length;
                    _queue.push({nodes[now.to][i].to,v_ans[nodes[now.to][i].to]});
                }
            } 
        }
        if(v_ans[v_ans.size()-1]!=-1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r",stdin);
    scanf("%lld%lld%lld",&n,&m,&d);//分别表示有n 个城市，m 条公路，歪嘴哦的血量为 b。
    money.resize(n);
    money_2.resize(n);
    nodes.resize(n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld",&money[i]);
        money_2[i] = money[i];
        if(i==0)
            first_money = money[i];
        if(i == n-1)
            last_money = money[i];
    }
    sort(money.begin(),money.end());
    for (ll i = 0; i < m; i++)
    {
        ll from,to,length;
        scanf("%lld%lld%lld",&from,&to,&length);
        if(--to!=--from)
        {
            nodes[from].push_back({to,length});
            nodes[to].push_back({from,length});
        }
    }
    ll left = 0,right = n-1;
    while (left <= right)
    {
        ll mid = (left + right)/2;
        if(SPFA(money[mid]))
        {
            ans = money[mid];
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    switch (ans)
    {
    case 9223372036854775807:
        printf("%s\n","AFK");
        break;
    
    default:
        printf("%lld",ans);
        break;
    }
    return 0;
}
