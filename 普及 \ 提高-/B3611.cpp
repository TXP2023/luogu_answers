#include <vector>
#include <queue>
#include <stdio.h>
#define fro(i) for(ll i=0;i<N;i++)

using namespace std;

typedef long long ll;

vector< vector< ll > > v;
ll N;

int main()
{
    scanf("%lld",&N);
    v.resize(N);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N);
        for (ll j = 0; j < N; j++)
        {
            scanf("%lld",&v[i][j]);
        }
    }
    fro(k)
    {
        fro(i)
        {
            fro(j)
            {
                //if(v[i][k] == 1 && v[k][j] == 1 )
                 v[i][j] = v[i][j] || (v[i][k] && v[k][j]); 
            }   
        }
    }
    fro(i)
    {
        fro(j)
        {
            printf("%lld ",v[i][j]);
        }
        printf("\n");
    }
    return 0;

}
