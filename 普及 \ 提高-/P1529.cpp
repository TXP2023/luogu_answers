#include <vector>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#define ll_NAXN 9223372036854775807

typedef long long ll;

using namespace std;

struct node
{
    ll to,length;
     bool operator <(const node &a)const{
		return length<a.length;
	}
};

priority_queue< node > _queue;
vector< vector< ll > > v;
vector< bool > vb;
vector< ll > ans;
ll N ;

inline void SPFA()
{
    _queue.push({25,0});
    while (!_queue.empty())
    {
        ll nxt = _queue.top().to,lenght = _queue.top().length;
        _queue.pop();
        for (ll i = 0; i < 52; i++)
        {
            if(v[nxt][i] != ll_NAXN && v[nxt][i] + lenght < ans[i])
            {
                ans[i] = v[nxt][i] + lenght;
                _queue.push({i,ans[i]});
            }
        }
    }
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld",&N);
    v.resize(52);
    vb.resize(52,false);
    ans.resize(52,ll_NAXN);
    ans[25] = 0;
    for (ll i = 0; i < 52; i++)
    {
        v[i].resize(52,ll_NAXN);
    }
    for (ll i = 0; i < N; i++)
    {
        ll from,to,length;
        char cfrom,cto;
        //scanf("%c%c%lld",&cfrom,&cto,&length);
        cin>>cfrom>>cto>>length;
        if(cfrom >= 'A' && cfrom <= 'Z')
        {
            from = cfrom - 'A';
            if(cfrom != 'Z')
                vb[from] = true;
        }
        else
        {
            from = cfrom - 'a' + 26;
        }
        if(cto >= 'A' && cto <= 'Z')
        {
            to = cto - 'A';
            if(cto != 'Z')
                vb[to] = true;
        }
        else
        {
            to = cto - 'a' + 26;
        }
        if(v[from][to] > length)
        {
            v[from][to] = length;
            v[to][from] = length;
        }
    }
    SPFA();
    ll big = 0;
    for (ll i = 0; i < 52; i++)
    {
        if(ans[i] < ans[big] && vb[i] == true)
            big  = i;
    }
    char out;
    if(big<=25)
    {
        out = 'A' + big;
        cout<<out<<' '<<ans[big];
    }
    else
    {
        out = 'a' + big - 26;
        cout<<out<<' '<<ans[big];
    }

}
