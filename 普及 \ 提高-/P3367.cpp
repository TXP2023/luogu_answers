#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<string,string> vch;

string stl_find(string str)
{
    if(vch[str]==str)
    {
        return str;
    }
    else
    {
        return vch[str]=stl_find(vch[str]);
    }
}

bool stl_inquire(string A, string B)
{
    if(stl_find(A)==stl_find(B))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    ll N,M;
    scanf("%lld%lld",&N,&M);
    //v.reserve(N);
    for(int i = 0; i < N; i++)
    {
        string str;
        //scanf("%s",&str);
        cin>>str;
        vch[str]=str;
    }
    for(ll i = 0; i < M; i++)
    {
        string strA, strB;
        //scanf("%s%s",&strA,&strB);
        cin>>strA>>strB;
        vch[stl_find(strA)]=stl_find(strB);
    }
    ll q;
    cin>>q;
    for (ll i = 0; i < q; i++)
    {
        string strA, strB;
        cin>>strA>>strB;
        if(stl_inquire(strA,strB))
        {
            printf("Yes.\n");
        }
        else
        {
            printf("No.\n");
        }
    }
    return 0;
}
