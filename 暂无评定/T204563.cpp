#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector< vector< ll > > v;
vector< bool > vbool;
queue< ll > vq;
ll N;

void BFS(  )
{
    vq.push(0);
    vbool[0] = true;
    printf("%lld",0);
    while (!vq.empty())
    {
        ll n = vq.front();
        vq.pop();
        vbool[0] = true;
        
        for (ll i = 0; i < N; i++)
        {
            if(v[n][i] == 1 && vbool[i] == false)
            {
                vq.push(i);
                vbool[i] = true;
                printf("%c%lld",'-',i);
            }
        }
    }
    
}

int main()
{
    N=7;
    v.resize(N);
    vbool.resize(N,false);
    for (int i = 0; i < N; i++)
    {
        v[i].resize(N);
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            scanf("%lld", &v[i][j]);
        }
    }
    BFS();
    return 0;
}
