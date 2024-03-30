#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n;
struct peo
{
    ll name;
    ll math;
};

bool  cmp(peo x,peo y)
{
	return x.math>y.math;//从大到小排>，若要从小到大排则<
}

int main()
{
    scanf("%lld%lld",&n,&m);
    ll M = m*1.5-1;
    peo peo[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld",&peo[i].name,&peo[i].math);
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(peo[j].math < peo[j+1].math)
            {
                swap(peo[j],peo[j+1]);
            }
        }
    }
    */
    //sort(peo.math.begin(),peo.math.end());
    //sort(peo->math,peo->math+n);
    sort(peo+0,peo+n,cmp);
    ll lj=0;
    for (int i = 0; i < n; i++)
    {
        if(peo[i].math >= peo[M].math)
        {
            lj++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if((peo[j].math == peo[j+1].math) && (peo[j+1].name < peo[j].name))
            {
                swap(peo[j],peo[j+1]);
            }
        }
    }
    //cout<<peo[M].math<<' '<<lj<<endl;
    printf("%lld%c%lld%c",peo[M].math,' ',lj,'\n');
    for (int i = 0; i < n; i++)
    {
        if(peo[i].math >= peo[M].math)
        {
            //cout<<peo[i].name<<' '<<peo[i].math<<endl;
            printf("%lld%c%lld%c",peo[i].name,' ',peo[i].math,'\n');
        }
        else
        {
            break;
        }
    }
    return 0;
}
