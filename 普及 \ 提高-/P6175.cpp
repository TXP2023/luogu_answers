#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <iostream>
#define MAX 1e9+7

using namespace std;

typedef long long ll;

vector< vector< ll > > v,e;//邻接矩阵
ll N,M,ans = MAX;

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    //scanf("%lld%lld",&N,&M);
    cin>>N>>M;
    v.resize(N);
    e.resize(N);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N,MAX);
        e[i].resize(N,MAX);
    }
    for (ll i = 0; i < M; i++)
    {
        ll from,to,length;
        scanf("%lld%lld%lld",&from,&to,&length);
        if(v[--from][--to] > length)
        {
            v[from][to] = length;
            v[to][from] = length;
            e[from][to] = length;
            e[to][from] = length;
        }
    }
    for(int k=0;k<N;k++)
    {
		for(int i=0;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans = min(ans,v[i][j]+e[i][k]+e[k][j]);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
            {
				v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
				v[j][i] = v[i][j];
			}
		
	}
    switch (ans)
    {
    case 1000000007:
        printf("No solution.\n");
        break;
    
    default:
        printf("%lld\n",ans);
        break;
    }

}
