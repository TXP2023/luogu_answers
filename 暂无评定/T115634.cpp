#include <bits/stdc++.h>
#define ll long long

using namespace std;

const short LX[4]{0,0,-1,1},LY[4]{1,-1,0,0};
vector< vector< bool > > v;
ll N,M,ans=0;

void DFS(ll x,ll y)
{
    for (short i = 0; i < 4; i++)
    {
        ll xi = x+LX[i],yi = y+LY[i];
        if(x+LX[i] >= 0 && x+LX[i]<N && y+LY[i] >= 0&& y+LY[i]<M )// 上 下 左 右
        {
            if(v[y+LY[i]][ x+LX[i]] == true)
            {
                ans++;
                v[y+LY[i]][ x+LX[i]] = false;
                DFS(x+LX[i],y+LY[i]);
            }
        }
    }
    return;
}

void NEXT()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    
    scanf("%lld%lld",&N,&M);
    if(N == 0 && M == 0)
    {
        exit(0);
    }
    v.resize(M);
    ll X,Y;
    for (ll i = 0; i < M; i++)
    {
        v[i].resize(N);
        for (ll j = 0; j < N; j++)
        {
            char IN;
            cin>>IN;
            switch (IN)
            {
            case '.':
                v[i][j] = true;
                break;
            
            case '#':
                v[i][j] = false;
                break;
            case '@':
                v[i][j] = true;
                X = j,Y = i;
                break;
            }
        }
    }
    v[Y][X] = false;
    DFS(X,Y);
    printf("%lld\n",ans+1);
    ans=0;
    return;
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    while(true)
    {
        NEXT();
    }
    return 0;
}
