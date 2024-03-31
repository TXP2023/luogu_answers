#include <bits/stdc++.h>
#define ll int

using namespace std;

vector< vector< ll > > v;
vector< bool > vis;
ll min,N,M,ans = 0;

void Prim(ll n)
{
    ll MAX,X,Y;
    vis[n] = true;
    for (ll i = 0; i < N-1; i++)
    {
        MAX = 2147483647;
        for (ll j = 0; j < N; j++)
        {
            if(vis[j])
            {
                for (ll k = 0; k < N; k++)
                {
                    if(!vis[k] && v[j][k]<MAX && v[j][k]!=-1)
                    {
                        MAX = v[j][k];
                        Y = k;
                    }
                }
            }
        }
        vis[Y] = true;
        //ans += MAX;
        if(MAX > ans)
        {
            ans = MAX;
        }
    }
    printf("%d\n",ans);
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%d%d",&N,&M);
    cout<<N-1<<' ';
    v.resize(N);
    vis.resize(N,false);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N,-1);
    }
    for (ll i = 0; i < M; i++)
    {
        ll A,B,Z;
        scanf("%d%d%d",&A,&B,&Z);
        if(A!=B && (Z<v[--A][--B] || v[A][B]==-1))
        {
            v[A][B] = Z;
            v[B][A] = Z;
        }
    }
    Prim(0);
    return 0;   
}
