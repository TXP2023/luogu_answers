#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct Edge
{
    float from,to,right;
};

struct station
{
    ll x,y;
};


vector< vector< float > > vlong;
vector< Edge > edges;
vector< station > stations;
vector< ll > v;
float ans = 0;
ll N,M;

bool cmp(Edge a, Edge b)
{
    return a.right < b.right;
}

ll find(ll a)
{
    if(v[a] == a)
    {
        return a;
    }
    else
    {
        return v[a] = find(v[a]);
    }
}

float Tpa(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%lld%lld",&M,&N);//N个节点M条边
    vlong.resize(N);
    v.resize(N);
    for (ll i = 0; i < N; i++)//初始化
    {
        v[i] = i;
        vlong[i].resize(N,-1);
    }
    for (ll i = 0; i < N; i++)//输入
    {
        station ston;
        scanf("%lld%lld",&ston.x,&ston.y);
        stations.push_back(ston);
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if(i != j)
            {
                vlong[i][j] = Tpa(stations[i].x,stations[i].y,stations[j].x,stations[j].y);
            }
        }
        
    }
    
    for (ll i = 0; i < N; i++)//加入edges
    {
        for (ll j = 0; j < N; j++)
        {
            if(vlong[i][j] != -1 /*&& i<j*/)
            {
                Edge EDGE;
                EDGE.right = vlong[i][j];
                EDGE.to = i;
                EDGE.from = j;
                edges.push_back(EDGE);
            }
        }
    }
    
    sort(edges.begin() ,edges.end() ,cmp);

    ll n = 1,i=0;
    while(n < N-M+1)//计算
    {
        if(find( edges[i].from ) != find( edges[i].to ))
        {
            v[find( edges[i].from )] = find( edges[i].to );
            if(edges[i].right>ans)
            {
                ans = edges[i].right;
            }
            //ans += edges[i].right;
            n++;
        }
        i++;
    }
    printf("%.2lf\n",ans);
    return 0;
}
